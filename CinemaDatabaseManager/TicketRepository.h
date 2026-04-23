#pragma once

#include "Repository.h"
#include "TicketModel.h"
#include "Database.h"

class TicketRepository : public Repository<Ticket> {
public:
	explicit TicketRepository(Database& db) : Repository(db) {}

	std::vector<Ticket> getAll() override;
	Ticket getById(int id) override;
	bool add(const Ticket& t) override;
	bool update(const Ticket& t) override;
	bool remove(int id) override;

	std::vector<Ticket> getByClientId(int clientId);
	std::vector<Ticket> getByScheduleId(int scheduleId);

private:
	Ticket rowToTicket(PGresult* res, int row);
};