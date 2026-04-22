#pragma once

#include "EmployeeService.h"
#include "CinemaService.h"
#include "BaseUI.h"

class EmployeeUI : public BaseUI {
public:
	EmployeeUI(EmployeeService& svc, CinemaService& cinemaSvc) : svc_(svc), cinemaSvc_(cinemaSvc) {}
	void show() override;

private:
	EmployeeService& svc_;
	CinemaService& cinemaSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Employee& e);
	void editEmployee(const Employee& e);

	void printAvailableCinemas();
};