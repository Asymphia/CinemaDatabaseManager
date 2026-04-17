#include "EmployeeUI.h"

void EmployeeUI::show() {
	while (true) {
		printTitle("Employees");

		std::cout << "1. View all" << std::endl;
		std::cout << "2. Add new" << std::endl;
		std::cout << "3. Search by ID" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl << "Choice: ";

		int c = readInt();

		switch (c) {
		case 1:
			viewAll();
			break;
		case 2:
			addNew();
			break;
		case 3:
			searchById();
			break;
		default:
			break;
		}
	}
}

void EmployeeUI::viewAll() {
	printTitle("All employees");

	auto employees = svc_.getAll();

	if (employees.empty()) {
		std::cout << "No employees found." << std::endl;
		pause();

		return;
	}

	for (auto& e : employees) {
		std::cout << "ID: " << e.getId();
		std::cout << ", Cinema: " << e.getCinemaId();
		std::cout << ", Name: " << e.getName();
		std::cout << ", Surname: " << e.getSurname();
		std::cout << ", Phone number: " << e.getNumber();
		std::cout << ", E-mail: " << e.getEmail();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No employee found" << std::endl;
		pause();
	}
}

void EmployeeUI::showDetail(const Employee& e) {
	printTitle("Employee" + std::to_string(e.getId()));

	std::cout << "Cinema: " << e.getCinemaId() << std::endl;
	std::cout << "Name: " << e.getName() << std::endl;
	std::cout << "Surname: " << e.getSurname() << std::endl;
	std::cout << "E-mail: " << e.getEmail() << std::endl;
	std::cout << "Phone number: " << e.getNumber() << std::endl;

	std::cout << "1. Edit" << std::endl;
	std::cout << "2. Delete" << std::endl;
	std::cout << "0. Back" << std::endl;
	std::cout << "Choice: ";
	int ch = readInt();

	switch (ch) {
	case 1:
		editEmployee(e);
		break;
	case 2: {
		if (svc_.remove(e.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void EmployeeUI::addNew() {
	printTitle("Add employee");

	std::cout << "Cinema Id: ";
	int cinemaId = readInt();
	std::string name = readLine("Name");
	std::string surname = readLine("Surname");
	std::string email = readLine("E-mail");
	std::string phone = readLine("Phone number");

	if (!cinemaId || name.empty() || surname.empty() || email.empty() || phone.empty()) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Employee e(0, cinemaId, name, surname, phone, email);

	if (svc_.add(e)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void EmployeeUI::editEmployee(const Employee& e) {
	printTitle("Edit employee");

	std::cout << "Cinema Id: ";
	int cinemaId = readInt();
	std::string name = readLine("Name");
	std::string surname = readLine("Surname");
	std::string email = readLine("E-mail");
	std::string phone = readLine("Phone number");

	Employee updated(0, cinemaId, name, surname, phone, email);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void EmployeeUI::searchById() {
	printTitle("Search by ID");

	std::cout << "Employee ID: ";
	int id = readInt();

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "Employee not found" << std::endl;
		pause();
	}
}