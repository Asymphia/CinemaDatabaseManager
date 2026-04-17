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