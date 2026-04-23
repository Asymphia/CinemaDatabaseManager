#include "TicketTypeUI.h"

void TicketTypeUI::show() {
	while (true) {
		printTitle("Ticket Types");

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

void TicketTypeUI::viewAll() {
	printTitle("All ticket types");

	auto ticketTypes = svc_.getAll();

	if (ticketTypes.empty()) {
		std::cout << "No ticket types found." << std::endl;
		pause();

		return;
	}

	for (auto& t : ticketTypes) {
		std::cout << "ID: " << t.getId();
		std::cout << ", Type: " << t.getType();
		std::cout << ", Price: " << t.getPrice();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No ticket type found" << std::endl;
		pause();
	}
}

void TicketTypeUI::showDetail(const TicketType& t) {
	printTitle("Ticket Type" + std::to_string(t.getId()));

	std::cout << "Type: " << t.getType() << std::endl;
	std::cout << "Price: " << t.getPrice() << std::endl;

	std::cout << std::endl << "Tickets" << std::endl;
	auto tickets = ticketSvc_.getByTicketTypeId(t.getId());
	if (tickets.empty()) {
		std::cout << "No ticket found" << std::endl;
	}
	else {
		for (auto ti : tickets) {
			std::cout << "Ticket ID: " << ti.getId();
			std::cout << ", Schedule ID: " << ti.getScheduleId();
			std::cout << ", Client ID: " << ti.getClientId();
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
		editTicketType(t);
		break;
	case 2: {
		if (svc_.remove(t.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void TicketTypeUI::addNew() {
	printTitle("Add ticket type");

	std::string type = readLine("Type");
	
	std::cout << "Price: ";
	double price;

	while (!(std::cin >> price)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Enter a number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (type.empty() || !price) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	TicketType t(0, type, price);

	if (svc_.add(t)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void TicketTypeUI::editTicketType(const TicketType& t) {
	printTitle("Edit ticket type");

	std::string type = readLine("Type");

	std::cout << "Price: ";
	double price;

	while (!(std::cin >> price)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Enter a number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	TicketType updated(0, type, price);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}