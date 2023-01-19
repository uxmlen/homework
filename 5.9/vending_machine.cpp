#include <iostream>

#include "vending_machine.h"

VendingMachine::VendingMachine(unsigned int slots_number)
{
    if (slots_number < 0) {
        std::cerr << "error: количество слотов не может быть меньше нуля";
        exit(1);
    }
    free_slots = slots_number;
}

void VendingMachine::addSlot(SnackSlot *slot)
{
    if (full_slots > free_slots) 
    {
        std::cerr << "error: в автомате со snake'ами закончилось место";
        exit(1);
    }
    full_slots++;
    slots.push_back(slot);

}

SnackSlot *VendingMachine::getSlot(unsigned int number_slot) const
{
    if (number_slot > full_slots) {
        std::cerr << "слота с таким номером не существует.";
        exit(1);
    }
    return slots[number_slot - 1];
}

unsigned int VendingMachine::getEmptySlotsCount() const
{
    return free_slots;
}
