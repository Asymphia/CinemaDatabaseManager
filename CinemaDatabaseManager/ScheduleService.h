#pragma once

#include "ScheduleRepository.h"
#include "ScheduleModel.h"
#include "Service.h"

class ScheduleService : public Service<Schedule> {
public:
	explicit ScheduleService(ScheduleRepository& repo) : repo_(repo) {}

	bool validate(const Schedule& s) override;

	std::vector<Schedule> getAll();
	Schedule getById(int id);
	bool add(const Schedule& s);
	bool update(const Schedule& s);
	bool remove(int id);

private:
	ScheduleRepository& repo_;
};