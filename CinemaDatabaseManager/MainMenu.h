#pragma once
#include "CinemaService.h"
#include "ClientService.h"
#include "EmployeeService.h"
#include "MovieService.h"
#include "RoomService.h"
#include "ScheduleService.h"
#include "TicketService.h"
#include "TicketTypeService.h"

struct AppServices {
    CinemaService& cinema;
    RoomService& room;
    MovieService& movie;
    ScheduleService& schedule;
    ClientService& client;
    TicketTypeService& ticketType;
    TicketService& ticket;
    EmployeeService& employee;
};

class MainMenu {
public:
    explicit MainMenu(AppServices& svc) : svc_(svc) {}
    void run();
private:
    AppServices& svc_;
};