#pragma once

#include "TicketRepository.h"
#include "TicketModel.h"
#include "Service.h"

class TicketService : public Service<Ticket> {
public:
	explicit TicketService(TicketRepository& repo) : repo_(repo) {}

	bool validate(const Ticket& t) override;

    std::vector<Ticket> getAll();
    Ticket getById(int id);
    bool add(const Ticket& t);
    bool update(const Ticket& t);
    bool remove(int id);

    std::vector<Ticket> getByClientId(int clientId);
    std::vector<Ticket> getByScheduleId(int scheduleId);

private:
    TicketRepository& repo_;
};