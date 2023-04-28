#include <iostream>

#include "bad_range.h"
#include "intarray.h"

int main(void)
{
    IntArray array(10);

    for (size_t i = 0; i < array.length(); ++i)
        array[i] = i + 1;

    std::cout << "количество элементов -  " << array.length() << std::endl;
    array.remove(4);
    array.remove(2);

    std::cout << "удаляем два элемента - " << array.length() << std::endl;
    array.push_back(450);
    array.push_front(350);

    std::cout << "добавляем элемент в конец и в начало" << array.length()
              << std::endl;

    array.resize(15);

    std::cout << "изменяем размер контейнера " << array.length() << std::endl;
    array.insert(13, 251); // добавляем в произвольную позицию элемент

    std::cout << "число 4 под индексам " << array.find(4) << std::endl;
    for (size_t i = 0; i < array.length(); ++i)
        std::cout << array[i] << std::endl;
    try {
        array[-21421421];
    } catch (bad_range& err) {
        std::cout << err.what() << std::endl;
    }

    IntArray b = array;
    std::cout << "создаём новый контейнер b на основе array" << std::endl;
    b.resize(5);
    b.push_front(299);
    for (size_t i = 0; i < b.length(); ++i)
        std::cout << array[i] << std::endl;

    return 0;
}
