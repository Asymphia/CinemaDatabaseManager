#include "MainMenu.h"
#include "CinemaUI.h"

void MainMenu::show() {
    while (true) {
        printTitle("Cinema database manager");

        std::cout << "1. Cinema" << std::endl;
        std::cout << "2. Room" << std::endl;
        std::cout << "3. Movie" << std::endl;
        std::cout << "4. Schedule" << std::endl;
        std::cout << "5. Client" << std::endl;
        std::cout << "6. Ticket Type" << std::endl;
        std::cout << "7. Ticket" << std::endl;
        std::cout << "8. Employee" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << std::endl << "Choice: ";

        int choice = readInt();
        if (choice == 0) {
            break;
        }
        handleChoice(choice);
    }
}

void MainMenu::handleChoice(int choice) {
    switch (choice) {
    case 1: {
        CinemaUI ui(svc_.cinema);
        ui.show();
        break;
    }
    default: {
        std::cout << "Invalid argument" << std::endl;
        pause();
        break;
    }
    }
}