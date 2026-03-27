#pragma once

#include "MovieModel.h"
#include "Database.h"
#include "Repository.h"

class MovieRepository : public Repository<Movie> {
public:
	explicit MovieRepository(Database& db) : Repository(db) {}

	std::vector<Movie> getAll() override;
	Movie getById(int id) override;
	bool add(const Movie& m) override;
	bool update(const Movie& m) override;
	bool remove(int id) override;

private:
	Movie rowToMovie(PGresult* res, int row);
};