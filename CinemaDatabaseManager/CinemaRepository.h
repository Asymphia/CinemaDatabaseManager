#pragma once

#include "Repository.h"
#include "CinemaModel.h"

class CinemaRepository : public Repository<Cinema> {
public:
	explicit CinemaRepository(Database& db) : Repository(db) {}

	std::vector<Cinema> getAll() override;
	Cinema getById(int id) override;
	
	bool add(const Cinema& c) override;
	bool update(const Cinema& c) override;
	bool remove(int id) override;

private:
	Cinema rowToCinema(PGresult* res, int row);
};