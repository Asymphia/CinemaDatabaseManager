#include "ClientUI.h"

void ClientUI::show() {
	while (true) {
		printTitle("Clients");

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

void ClientUI::viewAll() {
	printTitle("All clients");

	auto clients = svc_.getAll();

	if (clients.empty()) {
		std::cout << "No clients found." << std::endl;
		pause();

		return;
	}

	for (auto& c : clients) {
		std::cout << "ID: " << c.getId();
		std::cout << ", Name: " << c.getName();
		std::cout << ", Surname: " << c.getSurname();
		std::cout << ", E-mail: " << c.getEmail();
		std::cout << ", Phone number: " << c.getNumber();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No client found" << std::endl;
		pause();
	}
}

void ClientUI::showDetail(const Client& c) {
	printTitle("Client" + std::to_string(c.getId()));

	std::cout << "Name: " << c.getName() << std::endl;
	std::cout << "Surname: " << c.getName() << std::endl;
	std::cout << "E-mail: " << c.getName() << std::endl;
	std::cout << "Phone number: " << c.getName() << std::endl;

	std::cout << "1. Edit" << std::endl;
	std::cout << "2. Delete" << std::endl;
	std::cout << "0. Back" << std::endl;
	std::cout << "Choice: ";
	int ch = readInt();

	switch (ch) {
	case 1:
		editClient(c);
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

void ClientUI::addNew() {
	printTitle("Add client");

	std::string name = readLine("Name");
	std::string surname = readLine("Surname");
	std::string email = readLine("E-mail");
	std::string phone = readLine("Phone number");

	if (name.empty() || surname.empty() || email.empty() || phone.empty()) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Client c(0, name, surname, email, phone);

	if (svc_.add(c)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void ClientUI::editClient(const Client& c) {
	printTitle("Edit client");

	std::string name = readLine("Name");
	std::string surname = readLine("Surname");
	std::string email = readLine("E-mail");
	std::string phone = readLine("Phone number");

	Client updated(0, name, surname, email, phone);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void ClientUI::searchById() {
	printTitle("Search by ID");

	std::cout << "Client ID: ";
	int id = readInt();

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "Client not found" << std::endl;
		pause();
	}
}