#include <iostream>
using namespace std;

#include "snack.h"
#include "snack_slot.h"
#include "vending_machine.h"

int main(void)
{
    setlocale(LC_ALL, "");
    
    // создаём торговый автомат с 10 слотами для Snack'ов
    VendingMachine *machine = new VendingMachine(10);
    // создаём 2x закуски 
    Snack *bounty = new Snack("Bounty");
    Snack *snickers = new Snack("Snickers");
    Snack *milkway = new Snack("MilkWay");
    Snack *twix = new Snack("twix");
    // создаем слот для Snack'ов 
    SnackSlot *slot = new SnackSlot(10);
    SnackSlot *slot2 = new SnackSlot(10);
    // добавляем в ячейки закуски
    slot->addSnack(bounty);
    slot->addSnack(snickers);
    slot->addSnack(snickers);
    slot->addSnack(milkway);
    slot->addSnack(snickers);
    slot2->addSnack(milkway);
    slot2->addSnack(twix);
    // ... можно добавить до 10 закусок
    cout << "элемент 2: " << slot->getElement(2) << endl;
    cout << "элемент 4: " << slot->getElement(4) << endl;
    cout << "элемент 5: " << slot->getElement(5) << endl;
    cout << "если элемента не существует то: " << slot->getElement(100) << endl;
    machine->addSlot(slot);
    machine->addSlot(slot2);
    std::cout << "5 элемент из первого слота: "  << machine->getSlot(1)->getElement(5) << endl;
    std::cout << "2 элемент из второго слота: "  << machine->getSlot(2)->getElement(2) << endl;
    std::cout << machine->getEmptySlotsCount();

    delete machine;
    delete slot;
    delete snickers;
    delete bounty;
    
    return 0;
}
