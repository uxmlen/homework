#pragma once

#include <cstdint>

class IntArray final {
    std::size_t length_ {}; // value-init
    int* data_ = nullptr;

public:
    IntArray() = default;

    // если new не сможет выделить память, то все равно будет
    // std::bad_alloc и объект не будет создан
    // так же блокируем неявные преобразование
    explicit IntArray(std::size_t length)
        : data_(new int[length])
        , length_(length)
    {
    }
    // deep copy
    IntArray(const IntArray& obj);

    void erase();
    // возвращает индекс или -1 если элемент не найден
    int find(int value) const;
    void remove(std::size_t index);
    void push_back(int value);
    void push_front(int value);
    void insert(std::size_t index, int value);
    void resize(std::size_t new_length);
    std::size_t length() const noexcept;

    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    IntArray& operator=(const IntArray& obj);

    ~IntArray();

private:
    void reallocate(int new_length);
};
