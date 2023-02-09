#pragma once

#include <cstdint>

class IntArray final
{
    std::size_t length_{}; // value-init
    int* data_ = nullptr;
public:
    IntArray() = default;
    explicit IntArray(int length);
    // deep copy
    IntArray(const IntArray& obj);

    void erase();
    // возвращает индекс или -1 если элемент не найден
    const int find(int value);
    void remove(std::size_t index);
    void push_back(int value);
    void push_front(int value);
    void insert(std::size_t index, int value);
    void resize(std::size_t new_length);
    std::size_t length() const noexcept;

    int& operator[](std::size_t index);
    IntArray& operator=(const IntArray& obj);
    
    ~IntArray();
private:
    void reallocate(int new_length);
};
