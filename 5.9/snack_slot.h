#pragma once

#include <vector>

#include "snack.h"

class SnackSlot
{
    // сколько может поместиться 
    unsigned int free_cells;
    // заполненные ячейки
    unsigned int full_cells = 0;
    std::vector<Snack*> one_slot; 
public:
    SnackSlot(unsigned int slot_number);
    void addSnack(Snack *new_snack);
    std::string getElement(unsigned int number) const;
};
