#pragma once

#include <cstdint>

#include "bad_length.h"
#include "bad_range.h"

template <typename T = int> class Array final {
    std::size_t length_ {}; // value-init
    T* data_ = nullptr;

public:
    Array() = default;

    // если new не сможет выделить память, то все равно будет
    // std::bad_alloc и объект не будет создан
    // так же блокируем неявные преобразование
    explicit Array(std::size_t length)
        : data_(new T[length])
        , length_(length)
    {
    }
    // deep copy
    Array(const Array& obj)
    {
        reallocate(obj.length());
        try {
            for (std::size_t index = 0; index < length_; ++index)
                data_[index] = obj.data_[index];
        } catch (...) {
            delete[] data_;
            throw;
        }
    }

    void erase()
    {
        delete[] data_;
        data_ = nullptr;
        length_ = 0;
    }

    // возвращает индекс или -1 если элемент не найден
    const int find(T value)
    {
        for (std::size_t index = 0; index < length_; ++index) {
            if (data_[index] == value) {
                return index;
            }
        }

        return -1;
    }

    void remove(std::size_t index)
    {
        if (index > length_)
            throw bad_range();

        if (length_ == 0) {
            erase();
            return;
        }
        int* new_data = new int[length_ - 1];
        // копируем все элементы до index
        for (std::size_t before = 0; before < index; ++before)
            new_data[before] = data_[before];
        // копируем все остальные значение после удалённого элемента
        for (std::size_t after = index + 1; after < length_; ++after)
            new_data[after - 1] = data_[after];

        delete[] data_;
        data_ = new_data;
        --length_;
    }

    void push_back(int value) { insert(length_, value); }

    void push_front(int value) { insert(0, value); }

    void insert(std::size_t index, T value)
    {
        if (index > length_)
            throw bad_range();

        int* new_data = new int[length_ + 1];

        for (std::size_t before = 0; before < index; ++before)
            new_data[before] = data_[before];
        // вставляем новый элемент
        new_data[index] = value;
        for (std::size_t after = index; after < length_; ++after)
            new_data[after + 1] = data_[after];

        delete[] data_;
        data_ = new_data;
        ++length_;
    }

    void resize(std::size_t new_length)
    {
        if (new_length == length_)
            return;
        if (new_length == 0) {
            erase();
            return;
        }

        int elements_to_copy = (new_length > length_) ? length_ : new_length;
        int* new_data = new int[new_length];

        for (int index = 0; index < elements_to_copy; ++index)
            new_data[index] = data_[index];

        delete[] data_;
        data_ = new_data;
        length_ = new_length;
    }

    std::size_t length() const noexcept { return length_; }

    int& operator[](std::size_t index)
    {
        if (index > length_)
            throw bad_range();

        return data_[index];
    }
    Array& operator=(const Array& obj)
    {
        if (&obj == this)
            return *this;

        reallocate(obj.length());

        for (std::size_t index = 0; index < length_; ++index)
            data_[index] = obj.data_[index];

        return *this;
    }

    ~Array() { delete[] data_; }

private:
    void reallocate(int new_length)
    {
        erase();

        if (new_length <= 0)
            throw bad_length();

        data_ = new int[new_length];
        length_ = new_length;
    }
};
