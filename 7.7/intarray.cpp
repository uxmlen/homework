#include "intarray.h"
#include "bad_length.h"
#include "bad_range.h"

IntArray& IntArray::operator=(const IntArray& obj)
{
    if (&obj == this)
        return *this;

    reallocate(obj.length());

    for (size_t index = 0; index < length_; ++index)
        data_[index] = obj.data_[index];

    return *this;
}

IntArray::IntArray(const IntArray& obj)
{
    reallocate(obj.length());
    try {
        for (size_t index = 0; index < length_; ++index)
            data_[index] = obj.data_[index];
    } catch (...) {
        delete[] data_;
        throw;
    }
}

void IntArray::reallocate(int new_length)
{
    erase();

    if (new_length <= 0)
        throw bad_length();

    data_ = new int[new_length];
    length_ = new_length;
}

void IntArray::erase()
{
    delete[] data_;
    data_ = nullptr;
    length_ = 0;
}

void IntArray::resize(std::size_t new_length)
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

int IntArray::find(int value) const
{
    for (size_t index = 0; index < length_; ++index) {
        if (data_[index] == value) {
            return index;
        }
    }

    return -1;
}

void IntArray::remove(std::size_t index)
{
    if (index > length_)
        throw bad_range();

    if (length_ == 0) {
        erase();
        return;
    }
    int* new_data = new int[length_ - 1];
    // копируем все элементы до index
    for (size_t before = 0; before < index; ++before)
        new_data[before] = data_[before];
    // копируем все остальные значение после удалённого элемента
    for (size_t after = index + 1; after < length_; ++after)
        new_data[after - 1] = data_[after];

    delete[] data_;
    data_ = new_data;
    --length_;
}

size_t IntArray::length() const noexcept { return length_; }

void IntArray::insert(size_t index, int value)
{
    if (index > length_)
        throw bad_range();

    int* new_data = new int[length_ + 1];

    for (size_t before = 0; before < index; ++before)
        new_data[before] = data_[before];
    // вставляем новый элемент
    new_data[index] = value;
    for (size_t after = index; after < length_; ++after)
        new_data[after + 1] = data_[after];

    delete[] data_;
    data_ = new_data;
    ++length_;
}

void IntArray::push_back(int value) { insert(length_, value); }

void IntArray::push_front(int value) { insert(0, value); }

int& IntArray::operator[](size_t index)
{
    if (index > length_)
        throw bad_range();

    return data_[index];
}

const int& IntArray::operator[](size_t index) const
{
    if (index > length_)
        throw bad_range();

    return data_[index];
}

IntArray::~IntArray() { delete[] data_; }
