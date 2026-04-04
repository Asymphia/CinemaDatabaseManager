#include "ScheduleService.h"
#include <iostream>
#include <regex>

bool ScheduleService::validate(const Schedule& s) {
	if (s.getRoomId() <= 0 || s.getMovieId() <= 0) {
		std::cerr << "Invalid room or movie id" << std::endl;
		return false;
	}

	std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
	if (std::regex_match(s.getDate(), datePattern) || s.getDate().size() != 10) {
		std::cerr << "Enter valid date" << std::endl;
		return false;
	}

	std::regex timePattern(R"(\d{2}:\d{2})");
	if (std::regex_match(s.getTime().substr(0, 5), timePattern) || s.getTime().size() < 4) {
		std::cerr << "Enter valid time" << std::endl;
		return false;
	}

	return true;
}

std::vector<Schedule> ScheduleService::sort(std::vector<Schedule> items, const std::string& field, bool ascening) {
	auto cmp = [&](const Schedule& a, const Schedule& b) {
		bool result = false;

		if (field == "date") result = a.getDate() < b.getDate();
		else if (field == "time") result = a.getTime() < b.getTime();
		else if (field == "movieid") result = a.getMovieId() < b.getMovieId();
		else if (field == "roomid") result = a.getRoomId() < b.getRoomId();
		else result = a.getId() < b.getId();

		return ascening ? result : !result;
	};

	std::sort(items.begin(), items.end(), cmp);
	return items;
}

std::vector<Schedule> ScheduleService::getAll() {
	return repo_.getAll();
}

std::vector<Schedule> ScheduleService::getByDate(const std::string& date) {
	return repo_.getByDate(date);
}

std::vector<Schedule> ScheduleService::getByMovieId(int movieId) {
	return repo_.getByMovieId(movieId);
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