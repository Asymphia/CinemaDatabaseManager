#include "EmployeeService.h"
#include <iostream>
#include <regex>

bool EmployeeService::validate(const Employee& e) {
	if (e.getCinemaId() <= 0) {
		std::cerr << "Invalid value" << std::endl;
		return false;
	}

	if (e.getName().empty() || e.getSurname().empty() || e.getEmail().empty()) {
		std::cerr << "Fields cannot be empty" << std::endl;
		return false;
	}

	std::regex emailPattern(R"(.+@.+\..+)");
	if (!std::regex_match(e.getEmail(), emailPattern)) {
		std::cerr << "Invalid email" << std::endl;
		return false;
	}

	return true;
}

std::vector<Employee> EmployeeService::getAll() {
	return repo_.getAll();
}

std::vector<Employee> EmployeeService::getByCinemaId(int cinemaId) {
	return repo_.getByCinemaId(cinemaId);
}

Employee EmployeeService::getById(int id) {
	return repo_.getById(id);
}

bool EmployeeService::add(const Employee& e) {
	if (!validate(e)) return false;

	return repo_.add(e);
}

bool EmployeeService::update(const Employee& e) {
	if (!validate(e)) return false;

	return repo_.update(e);
}

bool EmployeeService::remove(int id) {
	return repo_.remove(id);
}