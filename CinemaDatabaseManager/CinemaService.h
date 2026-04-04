#pragma once

#include "CinemaRepository.h"
#include "CinemaModel.h"
#include "Service.h"

class CinemaService : public Service<Cinema> {
public:
	explicit CinemaService(CinemaRepository& repo) : repo_(repo) {}

	bool validate(const Cinema& c) override;
	std::vector<Cinema> sort(std::vector<Cinema> items, const std::string& field, bool ascending = true) override;

	std::vector<Cinema> getAll();
	Cinema getById(int id);
	bool add(const Cinema& c);
	bool update(const Cinema& c);
	bool remove(int id);

private:
	CinemaRepository& repo_;
};