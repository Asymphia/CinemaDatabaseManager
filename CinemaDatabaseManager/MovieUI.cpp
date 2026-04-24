#include "MovieUI.h"

void MovieUI::show() {
	while (true) {
		printTitle("Movies");

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

void MovieUI::viewAll() {
	printTitle("All movies");

	auto movies = svc_.getAll();

	if (movies.empty()) {
		std::cout << "No movies found." << std::endl;
		pause();

		return;
	}

	for (auto& m : movies) {
		std::cout << "ID: " << m.getId();
		std::cout << ", Title: " << m.getTitle();
		std::cout << ", Description: " << m.getDescription();
		std::cout << ", Duration: " << m.getDuration() << " mins";
		std::cout << std::endl;
	}

	std::cout << std::endl << "Enter ID to view details or 0 to go back: ";
	int id = readInt();

	if (id == 0) return;

	try {
		showDetail(svc_.getById(id));
	}
	catch (...) {
		std::cout << "No movies found" << std::endl;
		pause();
	}
}

void MovieUI::showDetail(const Movie& m) {
	printTitle("Movie" + std::to_string(m.getId()));

	std::cout << "Title: " << m.getTitle() << std::endl;
	std::cout << "Description: " << m.getDescription() << std::endl;
	std::cout << "Duration: " << m.getDuration() <<" mins" << std::endl;

	std::cout << std::endl << "Schedule" << std::endl;
	auto schedules = scheduleSvc_.getByMovieId(m.getId());
	if (schedules.empty()) {
		std::cout << "No schedule found" << std::endl;
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
		editMovie(m);
		break;
	case 2: {
		if (svc_.remove(m.getId())) {
			std::cout << "Deleted" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
			pause();
		}
	}
	}
}

void MovieUI::addNew() {
	printTitle("Add movie");

	std::string title = readLine("Title");
	std::string description = readLine("Description");
	std::cout << "Duration: ";
	int duration = readInt();

	if (title.empty() || description.empty() || !duration) {
		std::cout << "All fields required." << std::endl;
		pause();

		return;
	}

	Movie m(0, title, description, duration);

	if (svc_.add(m)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}

void MovieUI::editMovie(const Movie& m) {
	printTitle("Edit movie");

	std::string title = readLine("Title");
	std::string description = readLine("Description");
	std::cout << "Duration: ";
	int duration = readInt();

	Movie updated(m.getId(), title, description, duration);

	if (svc_.update(updated)) {
		std::cout << "Added" << std::endl;
	}
	else {
		std::cout << "Failed" << std::endl;
	}

	pause();
}