#include <iostream>
#include <array>

#include "audio_speaker.h"
#include "fridge.h"
#include "tv_station.h"


int main(void)
{
    int battery_type = 1;
    size_t count = 5;
    char flag = 'y';
    Electronic *items[count];

    items[0] = new AudioSpeaker("JBL audio", 1500, battery_type, 15, 20, 250, 150);
    items[1] = new AudioSpeaker("new JBL audio", 2000, battery_type, 15, 20, 250, 150);
    items[2] = new Fridge("Холодильник", 10000, 30, 20, 4);
    items[3] = new Fridge("Холодильник 2", 15000, 30, 20, 4);
    items[4] = new TVStation("TV station new", 7000, 30, 40, 300);

    while(flag == 'y') {
        int choice;
        std::cout << "Какой товар вы хотите посмотреть?" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << i << " : " << items[i]->getProductName() << std::endl;
        }
        std::cout << "Выберите номер: ";
        std::cin >> choice; 
        if (choice >= count) {
            std::cerr << "ERROR: число не должно превышать " << count;
            return 1;
        }
        items[choice]->showInfo();
        std::cout << "продолжить? y/n" << std::endl;
        std::cin >> flag;
    }
    return 0;
}
