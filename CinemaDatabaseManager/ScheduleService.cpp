#include "ScheduleService.h"
#include <iostream>
#include <regex>

bool ScheduleService::validate(const Schedule& s) {
	if (s.getRoomId() <= 0 || s.getMovieId() <= 0) {
		std::cerr << "Invalid room or movie id" << std::endl;
		return false;
	}

	std::regex datePattern(R"(\d{2}-\d{2}-\d{4})");
	if (!std::regex_match(s.getDate(), datePattern) || s.getDate().size() != 10) {
		std::cerr << "Enter valid date" << std::endl;
		return false;
	}

	std::regex timePattern(R"(\d{2}:\d{2})");
	if (!std::regex_match(s.getTime().substr(0, 5), timePattern) || s.getTime().size() < 4) {
		std::cerr << "Enter valid time" << std::endl;
		return false;
	}

	return true;
}

std::vector<Schedule> ScheduleService::getAll() {
	return repo_.getAll();
}

Schedule ScheduleService::getById(int id) {
	return repo_.getById(id);
}

bool ScheduleService::add(const Schedule& s) {
	if (!validate(s)) return false;

	return repo_.add(s);
}

bool ScheduleService::update(const Schedule& s) {
	if (!validate(s)) return false;

	return repo_.update(s);
}

bool ScheduleService::remove(int id) {
	return repo_.remove(id);
}

std::vector<Schedule> ScheduleService::getByRoomId(int roomId) {
	return repo_.getByRoomId(roomId);
}