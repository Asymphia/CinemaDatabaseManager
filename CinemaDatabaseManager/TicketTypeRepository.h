#pragma once

#include "TicketTypeModel.h"
#include "Database.h"
#include "Repository.h"

class TicketTypeRepository : public Repository<TicketType> {
public:
	explicit TicketTypeRepository(Database& db) : Repository(db) {}

	std::vector<TicketType> getAll() override;
	TicketType getById(int id) override;
	bool add(const TicketType& tt) override;
	bool update(const TicketType& tt) override;
	bool remove(int id) override;

private:
	TicketType rowToTicketType(PGresult* res, int row);
};