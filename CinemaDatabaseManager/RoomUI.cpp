#include "RoomUI.h"

void RoomUI::show() {
	while (true) {
		printTitle("Rooms");

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

void RoomUI::viewAll() {
	printTitle("All rooms");

	auto rooms = svc_.getAll();

	if (rooms.empty()) {
		std::cout << "No rooms found." << std::endl;
		pause();

		return;
	}

	for (auto& r : rooms) {
		std::cout << "ID: " << r.getId();
		std::cout << ", Number of seats: " << r.getSeatsNum();
		std::cout << ", Cinema ID: " << r.getCinemaId();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No room found" << std::endl;
		pause();
	}
}

void RoomUI::showDetail(const Room& r) {
	printTitle("Room" + std::to_string(r.getId()));

	std::cout << "Number of seats: " << r.getSeatsNum() << std::endl;
	std::cout << "Cinema ID: " << r.getCinemaId() << std::endl;

	std::cout << std::endl << "Schedules" << std::endl;
	auto schedules = scheduleSvc_.getByRoomId(r.getId());
	if (schedules.empty()) {
		std::cout << "No schedules found" << std::endl;
	}
	else {
		for (auto s : schedules) {
			std::cout << "Schedule ID: " << s.getId();
			std::cout << ", Date: " << s.getDate();
			std::cout << ", Time: " << s.getTime();
			std::cout << ", Movie ID: " << s.getMovieId();
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
		editRoom(r);
		break;
	case 2: {
		if (svc_.remove(r.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void RoomUI::addNew() {
	printTitle("Add room");

	std::cout << "Number of seats: ";
	int seatsNum = readInt();

	printAvailableCinemas();
	std::cout << "Cinema ID: ";
	int cinemaId = readInt();

	if (!seatsNum || !cinemaId) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Room r(0, seatsNum, cinemaId);

	if (svc_.add(r)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void RoomUI::editRoom(const Room& r) {
	printTitle("Edit room");

	std::cout << "Number of seats: ";
	int seatsNum = readInt();

	printAvailableCinemas();
	std::cout << "Cinema ID: ";
	int cinemaId = readInt();

	Room updated(0, seatsNum, cinemaId);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void RoomUI::printAvailableCinemas() {
	auto cinemas = cinemaSvc_.getAll();

	if (cinemas.empty()) {
		std::cout << "No available cinemas" << std::endl;
		return;
	}

	std::cout << "Available cinemas: " << std::endl;
	for (auto& c : cinemas) {
		std::cout << "ID: " << c.getId();
		std::cout << ", Name: " << c.getName();
		std::cout << ", City: " << c.getCity();
		std::cout << ", House number: " << c.getHouseNumber();
		std::cout << std::endl;
	}
}