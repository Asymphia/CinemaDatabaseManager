#include "RoomRepository.h"
#include <stdexcept>

std::vector<Room> RoomRepository::getAll() {
	PGresult* res = db_.query("SELECT id, seatsnum, cinemaid FROM Room ORDER BY id");

	std::vector<Room> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToRoom(res, i));
	}

	Database::freeResult(res);
	return result;
}

Room RoomRepository::getById(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT id, seatsnum, cinemaid FROM Room WHERE id=$1", 1, params);

	if (!res || PQntuples(res) == 0) {
		Database::freeResult(res);
		throw std::runtime_error("Room not found: id=" + sid);
	}

	Room r = rowToRoom(res, 0);
	Database::freeResult(res);
	return r;
}

bool RoomRepository::add(const Room& r) {
	std::string sSeats = std::to_string(r.getSeatsNum());
	std::string sCinemaId = std::to_string(r.getCinemaId());
	const char* params[] = { sSeats.c_str(), sCinemaId.c_str() };

	PGresult* res = db_.queryParams("INSERT INTO Room (seatsnum, cinemaid) VALUES ($1,$2)", 2, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool RoomRepository::update(const Room& r) {
	std::string sid = std::to_string(r.getId());
	std::string sSeats = std::to_string(r.getSeatsNum());
	std::string sCinemaId = std::to_string(r.getCinemaId());
	const char* params[] = { sSeats.c_str(), sCinemaId.c_str(), sid.c_str() };

	PGresult* res = db_.queryParams("UPDATE Room SET seatsnum=$1, cinemaid=$2 WHERE id=$3", 3, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool RoomRepository::remove(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("DELETE FROM Room WHERE id = $1", 1, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

std::vector<Room> RoomRepository::getByCinemaId(int cinemaId) {
	std::string sid = std::to_string(cinemaId);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT id, seatsnum, cinemaid FROM Room WHERE cinemaid=$1 ORDER BY id", 1, params);

	std::vector<Room> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToRoom(res, i));
	}

	Database::freeResult(res);
	return result;
}

Room RoomRepository::rowToRoom(PGresult* res, int row) {
	return Room(
		colInt(res, row, 0),
		colInt(res, row, 1),
		colInt(res, row, 2)
	);
}