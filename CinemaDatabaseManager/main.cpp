#include <iostream>
#include <windows.h>
#include "Database.h"
#include "ConfigLoader.h"

#include "CinemaRepository.h"
#include "ClientRepository.h"
#include "EmployeeRepository.h"
#include "MovieRepository.h"
#include "RoomRepository.h"
#include "ScheduleRepository.h"
#include "TicketRepository.h"
#include "TicketTypeRepository.h"

#include "CinemaService.h"
#include "ClientService.h"
#include "EmployeeService.h"
#include "MovieService.h"
#include "RoomService.h"
#include "ScheduleService.h"
#include "TicketService.h"
#include "TicketTypeService.h"

#include "MainMenu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ConfigLoader config;
    Database db(config.getHost(), config.getPort(),
        config.getDbName(), config.getUser(), config.getPassword());

    if (!db.connect()) {
        std::cerr << "Error while connecting to the database" << std::endl;
        return 1;
    }

    CinemaRepository cinemaRepo(db);
    RoomRepository roomRepo(db);
    MovieRepository movieRepo(db);
    ScheduleRepository scheduleRepo(db);
    ClientRepository clientRepo(db);
    TicketTypeRepository ticketTypeRepo(db);
    TicketRepository ticketRepo(db);
    EmployeeRepository employeeRepo(db);

    CinemaService cinemaService(cinemaRepo);
    RoomService roomService(roomRepo);
    MovieService movieService(movieRepo);
    ScheduleService scheduleService(scheduleRepo);
    ClientService clientService(clientRepo);
    TicketTypeService ticketTypeService(ticketTypeRepo);
    TicketService ticketService(ticketRepo);
    EmployeeService employeeService(employeeRepo);

    AppServices services{
        cinemaService,
        roomService,
        movieService,
        scheduleService,
        clientService,
        ticketTypeService,
        ticketService,
        employeeService
    };

    MainMenu Menu(services);
    Menu.show();

    db.disconnect();

    return 0;
}