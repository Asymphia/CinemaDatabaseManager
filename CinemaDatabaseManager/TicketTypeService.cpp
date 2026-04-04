#include "TicketTypeService.h"
#include <iostream>

bool TicketTypeService::validate(const TicketType& tt) {
	if (tt.getType().empty()) {
		std::cerr << "Enter all fields" << std::endl;
		return false;
	}

	if (tt.getPrice() <= 0.0 || tt.getPrice() > 500.0) {
		std::cerr << "Enter valid price (from 0 to 500)" << std::endl;
		return false;
	}

	return true;
}

std::vector<TicketType> TicketTypeService::sort(std::vector<TicketType> items, const std::string& field, bool ascending) {
	auto cmp = [&](const TicketType& a, const TicketType& b) {
		bool result = false;

		if (field == "type") result = a.getType() < b.getType();
		else if (field == "price") result = a.getPrice() < b.getPrice();
		else result = a.getId() < b.getId();

		return ascending ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
}

std::vector<TicketType> TicketTypeService::getAll() {
	return repo_.getAll();
}

TicketType TicketTypeService::getById(int id) {
	return repo_.getById(id);
}

bool TicketTypeService::add(const TicketType& tt) {
	if (!validate(tt)) return false;

	return repo_.add(tt);
}

bool TicketTypeService::update(const TicketType& tt) {
	if (!validate(tt)) return false;

	return repo_.update(tt);
}

bool TicketTypeService::remove(int id) {
	return repo_.remove(id);
}