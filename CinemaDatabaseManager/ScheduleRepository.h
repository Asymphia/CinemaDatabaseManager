#pragma once

#include "Repository.h"
#include "ScheduleModel.h"
#include "Database.h"

class ScheduleRepository : public Repository<Schedule> {
public:
	explicit ScheduleRepository(Database& db) : Repository(db) {}

	std::vector<Schedule> getAll() override;
	Schedule getById(int id) override;
	bool add(const Schedule& s) override;
	bool update(const Schedule& s) override;
	bool remove(int id) override;

	std::vector<Schedule> getByDate(const std::string& date);
	std::vector<Schedule> getByMovieId(int movieId);

private:
	Schedule rowToSchedule(PGresult* res, int row);
};