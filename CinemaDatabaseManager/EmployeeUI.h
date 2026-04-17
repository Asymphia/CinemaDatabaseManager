#pragma once

#include "EmployeeService.h"
#include "BaseUI.h"

class EmployeeUI : public BaseUI {
public:
	explicit EmployeeUI(EmployeeService& svc) : svc_(svc) {}
	void show() override;

private:
	EmployeeService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Employee& e);
	void editEmployee(const Employee& e);
};