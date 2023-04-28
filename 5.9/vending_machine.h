#include "snack_slot.h"

class VendingMachine {
    unsigned int total_slots;
    unsigned int full_slots;
    std::vector<SnackSlot*> slots;

public:
    VendingMachine(unsigned int slot_count);
    // сеттеры
    void addSlot(SnackSlot* slot);
    // геттеры
    unsigned int getEmptySlotsCount() const;
    SnackSlot* getSlot(unsigned int number) const;
};
