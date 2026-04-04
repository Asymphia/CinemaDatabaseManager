#pragma once

#include "ScheduleRepository.h"
#include "ScheduleModel.h"
#include "Service.h"

class ScheduleService : public Service<Schedule> {
public:
	explicit ScheduleService(ScheduleRepository& repo) : repo_(repo) {}

	bool validate(const Schedule& s) override;
	std::vector<Schedule> sort(std::vector<Schedule> items, const std::string& field, bool ascening = true) override;

	std::vector<Schedule> getAll();
	std::vector<Schedule> getByDate(const std::string& date);
	std::vector<Schedule> getByMovieId(int movieId);
	Schedule getById(int id);
	bool add(const Schedule& s);
	bool update(const Schedule& s);
	bool remove(int id);

private:
	ScheduleRepository& repo_;
};