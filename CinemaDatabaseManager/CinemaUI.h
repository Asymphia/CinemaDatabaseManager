#pragma once

#include "CinemaService.h"
#include "BaseUI.h"
#include "EmployeeService.h"
#include "RoomService.h"

class CinemaUI : public BaseUI {
public:
	explicit CinemaUI(CinemaService& svc, RoomService& roomSvc, EmployeeService& employeeSvc) : svc_(svc), roomSvc_(roomSvc), employeeSvc_(employeeSvc) {}
	void show() override;

private:
    CinemaService& svc_;
    RoomService& roomSvc_;
    EmployeeService& employeeSvc_;

    void viewAll();
    void addNew();
    void searchById();
    void showDetail(const Cinema& c);
    void editCinema(const Cinema& c);
};