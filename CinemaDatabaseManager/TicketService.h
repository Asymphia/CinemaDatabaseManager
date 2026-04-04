#pragma once

#include "TicketRepository.h"
#include "TicketModel.h"
#include "Service.h"

class TicketService : public Service<Ticket> {
public:
	explicit TicketService(TicketRepository& repo) : repo_(repo) {}

	bool validate(const Ticket& t) override;
	std::vector<Ticket> sort(std::vector<Ticket> items, const std::string& field, bool ascending = true) override;

    std::vector<Ticket> getAll();
    std::vector<Ticket> getByClientId(int clientId);
    std::vector<Ticket> getByScheduleId(int scheduleId);
    Ticket getById(int id);
    bool add(const Ticket& t);
    bool remove(int id);

private:
    TicketRepository& repo_;
};