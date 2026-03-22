#include "CinemaRepository.h"
#include <stdexcept>

std::vector<Cinema> CinemaRepository::getAll() {
	PGresult* res = db_.query("SELECT * FROM Cinema ORDER BY id");

	std::vector<Cinema> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToCinema(res, i));
	}

	Database::freeResult(res);
	return result;
}

Cinema CinemaRepository::getById(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT * FROM Cinema WHERE id=$1", 1, params);

	if (!res || PQntuples(res) == 0) {
		Database::freeResult(res);
		throw std::runtime_error("Cinema not found");
	}

	Cinema c = rowToCinema(res, 0);
	
	Database::freeResult(res);
	return c;
}

bool CinemaRepository::add(const Cinema& c) {
	const char* params[] = {
		c.getName().c_str(),
		c.getCity().c_str(),
		c.getPostalCode().c_str(),
		c.getHouseNumber().c_str()
	};

	PGresult* res = db_.queryParams("INSERT INTO Cinema (name, city, postalcode, housenumber) VALUES ($1,$2,$3,$4)", 4, params);

	bool ok = res != nullptr;

	Database::freeResult(res);
	return ok;
}

bool CinemaRepository::update(const Cinema& c) {
	std::string sid = std::to_string(c.getId());

	const char* params[] = {
		c.getName().c_str(),
		c.getCity().c_str(),
		c.getPostalCode().c_str(),
		c.getHouseNumber().c_str(),
		sid.c_str()
	};

	PGresult* res = db_.queryParams("UPDATE Cinema SET name=$1, city=$2, postalcode=$3, housenumber=$4 WHERE id=$5", 5, params);

	bool ok = res != nullptr;

	Database::freeResult(res);
	return ok;
}

bool CinemaRepository::remove(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("DELETE FROM Cinema WHERE id=$1", 1, params);

	bool ok = (res != nullptr);

	Database::freeResult(res);
	return ok;
}

Cinema CinemaRepository::rowToCinema(PGresult* res, int row) {
	return Cinema(
		colInt(res, row, 0),
		col(res, row, 1),
		col(res, row, 2),
		col(res, row, 3),
		col(res, row, 4)
	);
}