#include "ClientService.h"
#include <iostream>
#include <regex>

bool ClientService::validate(const Client& c) {
	if (c.getName().empty() || c.getSurname().empty() || c.getEmail().empty()) {
		std::cerr << "Enter all fields" << std::endl;
		return false;
	}

	std::regex emailPattern(R"([a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,})");
	if (std::regex_match(c.getEmail(), emailPattern)) {
		std::cerr << "Invalid email" << std::endl;
		return false;
	}

	return true;
}

std::vector<Client> ClientService::sort(std::vector<Client> items, const std::string& field, bool ascending) {
	auto cmp = [&](const Client& a, const Client& b) {
		bool result = false;

		if (field == "name") result = a.getName() < b.getName();
		else if (field == "surname") result = a.getSurname() < b.getSurname();
		else if (field == "email") result = a.getEmail() < b.getEmail();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
}

std::vector<Client> ClientService::getAll() {
	return repo_.getAll();
}

Client ClientService::getById(int id) {
	return repo_.getById(id);
}

Client ClientService::getByEmail(const std::string& email) {
	return repo_.getByEmail(email);
}

bool ClientService::add(const Client& c) {
	if (!validate(c)) return false;

	return repo_.add(c);
}

bool ClientService::update(const Client& c) {
	if (!validate(c)) return false;

	return repo_.update(c);
}

bool ClientService::remove(int id) {
	return repo_.remove(id);
}