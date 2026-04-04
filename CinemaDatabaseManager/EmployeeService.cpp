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

	std::regex emailPattern(R"([a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,})");
	if (std::regex_match(e.getEmail(), emailPattern)) {
		std::cerr << "Invalid email" << std::endl;
		return false;
	}

	return true;
}

std::vector<Employee> EmployeeService::sort(std::vector<Employee> items, const std::string& field, bool ascending) {
	auto cmp = [&](const Employee& a, const Employee& b) {
		bool result = false;

		if (field == "name") result = a.getName() < b.getName();
		else if (field == "surname") result = a.getSurname() < b.getSurname();
		else if (field == "email") result = a.getEmail() < b.getEmail();
		else if (field == "cinemaid") result = a.getCinemaId() < b.getCinemaId();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
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