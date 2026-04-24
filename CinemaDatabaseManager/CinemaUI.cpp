#include "CinemaUI.h"

void CinemaUI::show() {
	while (true) {
		printTitle("Cinemas");

		std::cout << "1. View all" << std::endl;
		std::cout << "2. Add new" << std::endl;
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
		case 0:
			return;
		default:
			break;
		}
	}
}

void CinemaUI::viewAll() {
	printTitle("All cinemas");

	auto cinemas = svc_.getAll();

	if (cinemas.empty()) {
		std::cout << "No cinemas found." << std::endl;
		pause();

		return;
	}

	for (auto& c : cinemas) {
		std::cout << "ID: " << c.getId();
		std::cout << ", Name: " << c.getName();
		std::cout << ", City: " << c.getCity();
		std::cout << ", Postal code: " << c.getPostalCode();
		std::cout << ", House number: " << c.getHouseNumber();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();
	
	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No cinema found" << std::endl;
		pause();
	}
}

void CinemaUI::showDetail(const Cinema& c) {
	printTitle("Cinema" + std::to_string(c.getId()));

	std::cout << "Name: " << c.getName() << std::endl;
	std::cout << "City: " << c.getCity() << std::endl;
	std::cout << "Postal code: " << c.getPostalCode() << std::endl;
	std::cout << "House number: " << c.getHouseNumber() << std::endl;

	std::cout << std::endl << "Rooms:" << std::endl;
	auto rooms = roomSvc_.getByCinemaId(c.getId());
	if (rooms.empty()) {
		std::cout << "No rooms found" << std::endl;
	}
	else {
		for (auto r : rooms) {
			std::cout << "Room ID: " << r.getId();
			std::cout << ", Seats: " << r.getSeatsNum();
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << std::endl << "Employees:" << std::endl;
	auto employees = employeeSvc_.getBycinemaId(c.getId());
	if (employees.empty()) {
		std::cout << "No employees found" << std::endl;
	}
	else {
		for (auto e : employees) {
			std::cout << "Employee ID: " << e.getId();
			std::cout << ", Name: " << e.getName();
			std::cout << ", Surname: " << e.getSurname();
			std::cout << ", E-mail: " << e.getEmail();
			std::cout << ", Phone number: " << e.getNumber();
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << "1. Edit" << std::endl;
	std::cout << "2. Delete" << std::endl;
	std::cout << "0. Back" << std::endl;
	std::cout << "Choice: ";
	int ch = readInt();

	switch (ch) {
	case 1:
		editCinema(c);
		break;
	case 2: {
		if (svc_.remove(c.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void CinemaUI::addNew() {
	printTitle("Add cinema");

	std::string name = readLine("Name");
	std::string city = readLine("City");
	std::string post = readLine("Postal code");
	std::string house = readLine("House number");

	if (name.empty() || city.empty() || post.empty() || house.empty()) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Cinema c(0, name, city, post, house);

	if (svc_.add(c)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void CinemaUI::editCinema(const Cinema& c) {
	printTitle("Edit cinema");

	std::string name = readLine("Name", c.getName());
	std::string city = readLine("City", c.getCity());
	std::string post = readLine("Postal code", c.getPostalCode());
	std::string house = readLine("House number", c.getHouseNumber());

	Cinema updated(c.getId(), name, city, post, house);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}