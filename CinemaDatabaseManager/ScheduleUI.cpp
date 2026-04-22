#include "ScheduleUI.h"

void ScheduleUI::show() {
	while (true) {
		printTitle("Schedules");

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

void ScheduleUI::viewAll() {
	printTitle("All schedules");

	auto schedules = svc_.getAll();

	if (schedules.empty()) {
		std::cout << "No schedules found." << std::endl;
		pause();

		return;
	}

	for (auto& s : schedules) {
		std::cout << "ID: " << s.getId();
		std::cout << ", Room ID: " << s.getRoomId();
		std::cout << ", Movie ID: " << s.getMovieId();
		std::cout << ", Date: " << s.getDate();
		std::cout << ", Time: " << s.getTime();
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No schedule found" << std::endl;
		pause();
	}
}

void ScheduleUI::showDetail(const Schedule& s) {
	printTitle("Schedule" + std::to_string(s.getId()));

	std::cout << "Room ID: " << s.getRoomId() << std::endl;
	std::cout << "Movie ID: " << s.getMovieId() << std::endl;
	std::cout << "Date: " << s.getDate() << std::endl;
	std::cout << "Time: " << s.getTime() << std::endl;

	std::cout << "1. Edit" << std::endl;
	std::cout << "2. Delete" << std::endl;
	std::cout << "0. Back" << std::endl;
	std::cout << "Choice: ";
	int ch = readInt();

	switch (ch) {
	case 1:
		editSchedule(s);
		break;
	case 2: {
		if (svc_.remove(s.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void ScheduleUI::addNew() {
	printTitle("Add schedule");

	getAvailableRooms();
	std::cout << "Room ID: ";
	int roomId = readInt();

	getAvailableMovies();
	std::cout << "Movie ID: ";
	int movieId = readInt();

	std::string date = readLine("Date (in xx-xx-xxxx format)");
	std::string time = readLine("Time (in xx:xx format)");

	if (!roomId || !movieId || date.empty() || time.empty()) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Schedule s(0, roomId, movieId, date, time);

	if (svc_.add(s)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void ScheduleUI::editSchedule(const Schedule& s) {
	printTitle("Edit schedule");

	getAvailableRooms();
	std::cout << "Room ID: ";
	int roomId = readInt();

	getAvailableMovies();
	std::cout << "Movie ID: ";
	int movieId = readInt();

	std::string date = readLine("Date (in dd-mm-yyyy format)");
	std::string time = readLine("Time (in hh:mm format)");

	Schedule updated(0, roomId, movieId, date, time);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void ScheduleUI::searchById() {
	printTitle("Search by ID");

	std::cout << "Schedule ID: ";
	int id = readInt();

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "Schedule not found" << std::endl;
		pause();
	}
}

void ScheduleUI::getAvailableRooms() {
	auto rooms = roomSvc_.getAll();
	
	std::cout << "Available rooms: " << std::endl;

	if (rooms.empty()) {
		std::cout << "No room available" << std::endl;
		return;
	}

	for (auto& r : rooms) {
		std::cout << "ID: " << r.getId();
		std::cout << ", Cinema ID: " << r.getCinemaId();
		std::cout << std::endl;
	}
}

void ScheduleUI::getAvailableMovies() {
	auto movies = movieSvc_.getAll();

	std::cout << "Available movies:" << std::endl;

	if (movies.empty()) {
		std::cout << "No movie available" << std::endl;
		return;
	}

	for (auto& m : movies) {
		std::cout << "ID: " << m.getId();
		std::cout << ", Title: " << m.getTitle();
		std::cout << std::endl;
	}
}