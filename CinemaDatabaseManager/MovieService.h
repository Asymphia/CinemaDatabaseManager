#pragma once

#include "MovieRepository.h"
#include "MovieModel.h"
#include "Service.h"

class MovieService : public Service<Movie> {
public:
	explicit MovieService(MovieRepository& repo) : repo_(repo) {}

	bool validate(const Movie& m) override;
	std::vector<Movie> sort(std::vector<Movie> items, const std::string& field, bool ascending = true) override;

	std::vector<Movie> getAll();
	Movie getById(int id);
	bool add(const Movie& m);
	bool update(const Movie& m);
	bool remove(int id);

private:
	MovieRepository& repo_;
};