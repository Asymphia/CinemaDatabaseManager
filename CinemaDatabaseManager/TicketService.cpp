#include "TicketService.h"
#include <iostream>

bool TicketService::validate(const Ticket& t) {
	if (t.getScheduleId() <= 0 || t.getClientId() <= 0 || t.getTicketTypeId() <= 0) {
		std::cerr << "Invalid values" << std::endl;
		return false;
	}

	return true;
}

std::vector<Ticket> TicketService::sort(std::vector<Ticket> items, const std::string& field, bool ascending) {
    auto cmp = [&](const Ticket& a, const Ticket& b) {
        bool result = false;

        if (field == "scheduleid") result = a.getScheduleId() < b.getScheduleId();
        else if (field == "clientid") result = a.getClientId() < b.getClientId();
        else if (field == "tickettypeid") result = a.getTicketTypeId() < b.getTicketTypeId();
        else result = a.getId() < b.getId();

        return ascending ? result : !result;
    };

    std::sort(items.begin(), items.end(), cmp);
    return items;
}

std::vector<Ticket> TicketService::getAll() {
    return repo_.getAll();
}

std::vector<Ticket> TicketService::getByClientId(int clientId) {
    return repo_.getByClientId(clientId);
}

std::vector<Ticket> TicketService::getByScheduleId(int scheduleId) {
    return repo_.getByScheduleId(scheduleId);
}

Ticket TicketService::getById(int id) {
    return repo_.getById(id);
}

bool TicketService::add(const Ticket& t) {
    if (!validate(t)) return false;

    return repo_.add(t);
}

bool TicketService::remove(int id) {
    return repo_.remove(id);
}