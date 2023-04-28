#pragma once

#include <vector>

#include "snack.h"

class SnackSlot {
    // общее количество ячеек
    unsigned int total_cells;
    // количество заполненных ячеек
    unsigned int full_cells = 0;
    std::vector<Snack*> one_slot;

public:
    SnackSlot(unsigned int slot_number);
    void addSnack(Snack* new_snack);
    std::string getElement(unsigned int number) const;
};
