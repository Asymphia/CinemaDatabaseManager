#include "MovieService.h"
#include <iostream>

bool MovieService::validate(const Movie& m) {
	if (m.getTitle().empty()) {
		std::cerr << "Title cannot be empty" << std::endl;
		return false;
	}

	if (m.getDuration() <= 0 || m.getDuration() > 600) {
		std::cerr << "Enter valid duration (from 0 to 600)" << std::endl;
		return false;
	}

	return true;
}

std::vector<Movie> MovieService::sort(std::vector<Movie> items, const std::string& field, bool ascending) {
	auto cmp = [&](const Movie& a, const Movie& b) {
		bool result = false;

		if (field == "title") result = a.getTitle() < b.getTitle();
		else if (field == "duration") result = a.getDuration() < b.getDuration();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
}

std::vector<Movie> MovieService::getAll() {
	return repo_.getAll();
}

Movie MovieService::getById(int id) {
	return repo_.getById(id);
}

bool MovieService::add(const Movie& m) {
	if (!validate(m)) return false;

	return repo_.add(m);
}

bool MovieService::update(const Movie& m) {
	if (!validate(m)) return false;

	return repo_.update(m);
}

bool MovieService::remove(int id) {
	return repo_.remove(id);
}