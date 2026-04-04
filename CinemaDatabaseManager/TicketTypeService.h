#pragma once

#include "TicketTypeRepository.h"
#include "TicketTypeModel.h"
#include "Service.h"

class TicketTypeService : public Service<TicketType> {
public:
	explicit TicketTypeService(TicketTypeRepository& repo) : repo_(repo) {}

	bool validate(const TicketType& tt) override;
	std::vector<TicketType> sort(std::vector<TicketType> items, const std::string& field, bool ascending = true) override;

	std::vector<TicketType> getAll();
	TicketType getById(int id);
	bool add(const TicketType& tt);
	bool update(const TicketType& tt);
	bool remove(int id);

private:
	TicketTypeRepository& repo_;
};