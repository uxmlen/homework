#include <iostream>

#include "snack_slot.h"

SnackSlot::SnackSlot(unsigned int cells_number)
    : total_cells(cells_number)
{
    if (cells_number < 0) {
        std::cerr << "error: количество snack'ов не может быть меньше нуля";
        exit(1);
    }
}

void SnackSlot::addSnack(Snack* new_snack)
{
    if (full_cells > total_cells) {
        std::cerr << "error; в этом слоте закончилось место ";
        exit(1);
    }
    // повышаем счётчик заполненных ячеек
    full_cells++;
    one_slot.push_back(new_snack);
}

std::string SnackSlot::getElement(unsigned int number) const
{
    if (number > full_cells) {
        return "элемента не существует";
    }
    Snack* snack_from_slot = one_slot[number - 1];
    return snack_from_slot->getNameProduct();
}
