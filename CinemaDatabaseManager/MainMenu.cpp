#include "MainMenu.h"
#include "CinemaUI.h"
#include "ClientUI.h"
#include "EmployeeUI.h"
#include "MovieUI.h"
#include "RoomUI.h"
#include "ScheduleUI.h"
#include "TicketUI.h"

void MainMenu::show() {
    while (true) {
        printTitle("Cinema database manager");

        std::cout << "1. Cinema" << std::endl;
        std::cout << "2. Client" << std::endl;
        std::cout << "3. Employee" << std::endl;
        std::cout << "4. Movie" << std::endl;
        std::cout << "5. Room" << std::endl;
        std::cout << "6. Schedule" << std::endl;
        std::cout << "7. Ticket" << std::endl;
        std::cout << "8. Ticket Type" << std::endl;
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
    case 2: {
        ClientUI ui(svc_.client);
        ui.show();
        break;
    }
    case 3: {
        EmployeeUI ui(svc_.employee);
        ui.show();
        break;
    }
    case 4: {
        MovieUI ui(svc_.movie);
        ui.show();
        break;
    }
    case 5: {
        RoomUI ui(svc_.room);
        ui.show();
        break;
    }
    case 6: {
        ScheduleUI ui(svc_.schedule);
        ui.show();
        break;
    }
    case 7: {
        TicketUI ui(svc_.ticket);
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