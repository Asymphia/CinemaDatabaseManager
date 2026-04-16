#include "MainMenu.h"
#include "CinemaUI.h"
#include <iostream>
#include <limits>

static int readInt() {
    int v;
    while (!(std::cin >> v)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return v;
}

void MainMenu::run() {
    while (true) {
        system("cls");

        std::cout << std::endl;
        std::cout << "  ================================\n";
        std::cout << "    CINEMA DATABASE MANAGER\n";
        std::cout << "  ================================\n\n";
        std::cout << "  1. Cinema\n";
        std::cout << "  2. Room\n";
        std::cout << "  3. Movie\n";
        std::cout << "  4. Schedule\n";
        std::cout << "  5. Client\n";
        std::cout << "  6. Ticket Type\n";
        std::cout << "  7. Ticket\n";
        std::cout << "  8. Employee\n";
        std::cout << "  0. Exit\n";
        std::cout << "\n  Choice: ";

        int choice = readInt();
        switch (choice) {
        case 1: { CinemaUI ui(svc_.cinema); ui.show(); break; }
              // case 2: { RoomUI ui(svc_.room);             ui.show(); break; }
              // case 3: { MovieUI ui(svc_.movie);           ui.show(); break; }
              // case 4: { ScheduleUI ui(svc_.schedule);     ui.show(); break; }
              // case 5: { ClientUI ui(svc_.client);         ui.show(); break; }
              // case 6: { TicketTypeUI ui(svc_.ticketType); ui.show(); break; }
              // case 7: { TicketUI ui(svc_.ticket);         ui.show(); break; }
              // case 8: { EmployeeUI ui(svc_.employee);     ui.show(); break; }
        case 0: return;
        default: std::cout << "Invalid choice.\n"; break;
        }
    }
}