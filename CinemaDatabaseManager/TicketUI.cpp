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

	getAvailableSchedules();
	std::cout << "Schedule ID: ";
	int scheduleId = readInt();

	getAvailableClients();
	std::cout << "Client ID: ";
	int clientId = readInt();

	getAvailableTicketTypes();
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

	getAvailableSchedules();
	std::cout << "Schedule ID: ";
	int scheduleId = readInt();

	getAvailableClients();
	std::cout << "Client ID: ";
	int clientId = readInt();

	getAvailableTicketTypes();
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

void TicketUI::getAvailableSchedules() {
	auto schedules = scheduleSvc_.getAll();

	std::cout << "Available schedules:" << std::endl;

	if (schedules.empty()) {
		std::cout << "No available schedules" << std::endl;
		return;
	}

	for (auto& s : schedules) {
		std::cout << "ID: " << s.getId();
		std::cout << ", Movie ID: " << s.getMovieId();
		std::cout << ", Room ID: " << s.getRoomId();
		std::cout << ", Date: " << s.getDate();
		std::cout << ", Time: " << s.getTime();
		std::cout << std::endl;
	}
}

void TicketUI::getAvailableClients() {
	auto clients = clientSvc_.getAll();

	std::cout << "Available clients:" << std::endl;

	if (clients.empty()) {
		std::cout << "No available clients" << std::endl;
		return;
	}

	for (auto& c : clients) {
		std::cout << "ID: " << c.getId();
		std::cout << ", Name: " << c.getName();
		std::cout << ", Surname: " << c.getSurname();
		std::cout << ", E-mail: " << c.getEmail();
		std::cout << std::endl;
	}
}

void TicketUI::getAvailableTicketTypes() {
	auto tts = ttSvc_.getAll();

	std::cout << "Available ticket types:" << std::endl;

	if (tts.empty()) {
		std::cout << "No available ticket types" << std::endl;
		return;
	}

	for (auto& tt : tts) {
		std::cout << "ID: " << tt.getId();
		std::cout << ", Type: " << tt.getType();
		std::cout << ", Price: " << tt.getPrice();
		std::cout << std::endl;
	}
}