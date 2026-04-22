#include "TicketUI.h"

void TicketUI::show() {
	while (true) {
		printTitle("Tickets");

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
		case 0:
			return;
		default:
			break;
		}
	}
}

void TicketUI::viewAll() {
	printTitle("All tickets");

	auto tickets = svc_.getAll();

	if (tickets.empty()) {
		std::cout << "No tickets found." << std::endl;
		pause();

		return;
	}

	for (auto& t : tickets) {
		std::cout << "ID: " << t.getId();
		std::cout << ", Schedule ID: " << t.getScheduleId();
		std::cout << ", Client ID: " << t.getClientId();
		std::cout << ", Ticket type ID: " << t.getTicketTypeId();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No ticket found" << std::endl;
		pause();
	}
}

void TicketUI::showDetail(const Ticket& t) {
	printTitle("Ticket" + std::to_string(t.getId()));

	std::cout << "Schedule ID: " << t.getScheduleId() << std::endl;
	std::cout << "Client ID: " << t.getClientId() << std::endl;
	std::cout << "Ticket type ID: " << t.getTicketTypeId() << std::endl;

	std::cout << "1. Edit" << std::endl;
	std::cout << "2. Delete" << std::endl;
	std::cout << "0. Back" << std::endl;
	std::cout << "Choice: ";
	int ch = readInt();

	switch (ch) {
	case 1:
		editTicket(t);
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

void TicketUI::addNew() {
	printTitle("Add ticket");

	std::cout << "Schedule ID: ";
	int scheduleId = readInt();
	std::cout << "Client ID: ";
	int clientId = readInt();
	std::cout << "Ticket type ID: ";
	int ticketTypeId = readInt();

	if (!scheduleId || !clientId || !ticketTypeId) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Ticket t(0, scheduleId, clientId, ticketTypeId);

	if (svc_.add(t)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void TicketUI::editTicket(const Ticket& t) {
	printTitle("Edit ticket");

	std::cout << "Schedule ID: ";
	int scheduleId = readInt();
	std::cout << "Client ID: ";
	int clientId = readInt();
	std::cout << "Ticket type ID: ";
	int ticketTypeId = readInt();

	Ticket updated(0, scheduleId, clientId, ticketTypeId);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void TicketUI::searchById() {
	printTitle("Search by ID");

	std::cout << "Ticket ID: ";
	int id = readInt();

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "Ticket not found" << std::endl;
		pause();
	}
}