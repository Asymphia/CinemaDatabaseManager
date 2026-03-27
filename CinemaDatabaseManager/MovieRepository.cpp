#include "MovieRepository.h"
#include <stdexcept>

std::vector<Movie> MovieRepository::getAll() {
	PGresult* res = db_.query("SELECT id, title, description, duration FROM Movie ORDER BY id");

	std::vector<Movie> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToMovie(res, i));
	}

	Database::freeResult(res);
	return result;
}

Movie MovieRepository::getById(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT id, title, description, duration FROM Movie WHERE id=$1", 1, params);

	if (!res || PQntuples(res) == 0) {
		Database::freeResult(res);
		throw std::runtime_error("Movie not found: id=" + sid);
	}

	Movie m = rowToMovie(res, 0);
	Database::freeResult(res);
	return m;
}

bool MovieRepository::add(const Movie& m) {
	std::string sDuration = std::to_string(m.getDuration());

	const char* params[] = {
		m.getTitle().c_str(),
		m.getDescription().c_str(),
		sDuration.c_str()
	};

	PGresult* res = db_.queryParams("INSERT INTO Movie (title, description, duration) VALUES ($1,$2,$3)", 3, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool MovieRepository::update(const Movie& m) {
	std::string sid = std::to_string(m.getId());
	std::string sDuration = std::to_string(m.getDuration());

	const char* params[] = {
		m.getTitle().c_str(),
		m.getDescription().c_str(),
		sDuration.c_str(),
		sid.c_str()
	};

	PGresult* res = db_.queryParams("UPDATE Movie SET title=$1, description=$2, duration=$3 WHERE id=$4", 4, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool MovieRepository::remove(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("DELETE FROM Movie WHERE id=$1", 1, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

Movie MovieRepository::rowToMovie(PGresult* res, int row) {
	return Movie(
		colInt(res, row, 0),
		col(res, row, 1),
		col(res, row, 2),
		colInt(res, row, 3)
	);
}