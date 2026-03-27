#include "ScheduleRepository.h"
#include <stdexcept>

std::vector<Schedule> ScheduleRepository::getAll() {
	PGresult* res = db_.query("SELECT id, roomid, movieid, date, time FROM Schedule ORDER BY date, time");

	std::vector<Schedule> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);

	for (int i = 0; i < rows; ++i) {
		result.push_back(rowToSchedule(res, i));
	}

	Database::freeResult(res);
	return result;
}

Schedule ScheduleRepository::getById(int id) {
	std::string sid = std::to_string(id);
	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT id, roomid, movieid, date, time FROM Schedule WHERE id=$1", 1, params);

	if (!res || PQntuples(res) == 0) {
		Database::freeResult(res);
		throw std::runtime_error("Schedule not found: id=" + sid);
	}

	Schedule s = rowToSchedule(res, 0);
	Database::freeResult(res);
	return s;
}

bool ScheduleRepository::add(const Schedule& s) {
	std::string sRoomId = std::to_string(s.getRoomId());
	std::string sMovieId = std::to_string(s.getMovieId());

	const char* params[] = {
		sRoomId.c_str(),
		sMovieId.c_str(),
		s.getDate().c_str(),
		s.getTime().c_str()
	};

	PGresult* res = db_.queryParams("INSERT INTO Schedule (roomid, movieid, date, time) VALUES ($1,$2,$3,$4)", 4, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool ScheduleRepository::update(const Schedule& s) {
	std::string sid = std::to_string(s.getId());
	std::string sRoomId = std::to_string(s.getRoomId());
	std::string sMovieId = std::to_string(s.getMovieId());

	const char* params[] = {
		sRoomId.c_str(),
		sMovieId.c_str(),
		s.getDate().c_str(),
		s.getTime().c_str(),
		sid.c_str()
	};

	PGresult* res = db_.queryParams("UPDATE Schedule SET roomid=$1, movieid=$2, date=$3, time=$4 WHERE id=$5", 5, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

bool ScheduleRepository::remove(int id) {
	std::string sid = std::to_string(id);

	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("DELETE FROM Schedule WHERE id = $1", 1, params);

	bool ok = (res != nullptr);
	Database::freeResult(res);
	return ok;
}

std::vector<Schedule> ScheduleRepository::getByDate(const std::string& date) {
	const char* params[] = { date.c_str() };

	PGresult* res = db_.queryParams("SELECT id, roomid, movieid, date, time FROM Schedule WHERE date=$1 ORDER BY time", 1, params);

	std::vector<Schedule> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToSchedule(res, i));
	}

	Database::freeResult(res);
	return result;
}

std::vector<Schedule> ScheduleRepository::getByMovieId(int movieId) {
	std::string sid = std::to_string(movieId);

	const char* params[] = { sid.c_str() };

	PGresult* res = db_.queryParams("SELECT id, roomid, movieid, date, time FROM Schedule WHERE movieid=$1 ORDER BY date, time", 1, params);

	std::vector<Schedule> result;

	if (!res) {
		return result;
	}

	int rows = PQntuples(res);
	for (int i = 0; i < rows; i++) {
		result.push_back(rowToSchedule(res, i));
	}

	Database::freeResult(res);
	return result;
}

Schedule ScheduleRepository::rowToSchedule(PGresult* res, int row) {
	return Schedule(
		colInt(res, row, 0),
		colInt(res, row, 1),
		colInt(res, row, 2),
		col(res, row, 3),
		col(res, row, 4)
	);
}