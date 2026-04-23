#include "TicketService.h"
#include <iostream>

bool TicketService::validate(const Ticket& t) {
	if (t.getScheduleId() <= 0 || t.getClientId() <= 0 || t.getTicketTypeId() <= 0) {
		std::cerr << "Invalid values" << std::endl;
		return false;
	}

	return true;
}

std::vector<Ticket> TicketService::getAll() {
    return repo_.getAll();
}

Ticket TicketService::getById(int id) {
    return repo_.getById(id);
}

bool TicketService::add(const Ticket& t) {
    if (!validate(t)) return false;

    return repo_.add(t);
}

bool TicketService::update(const Ticket& t) {
    if (!validate(t)) return false;

    return repo_.update(t);
}

bool TicketService::remove(int id) {
    return repo_.remove(id);
}

std::vector<Ticket> TicketService::getByClientId(int clientId) {
    return repo_.getByClientId(clientId);
}

std::vector<Ticket> TicketService::getByScheduleId(int scheduleId) {
    return repo_.getByScheduleId(scheduleId);
}