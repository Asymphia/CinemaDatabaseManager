#include "MovieModel.h"
#include <sstream>

Movie::Movie(int id, const std::string& title,
	const std::string& description, int duration)
	: id_(id), title_(title), description_(description), duration_(duration) {}

int Movie::getId() const {
	return id_;
}

std::string Movie::getTableName() const {
	return "Movie";
}

std::string Movie::toString() const {
	std::ostringstream oss;

	oss << "[" << id_ << "] " << title_ << " | " << duration_ << " min" << " | " << description_;

	return oss.str();
}

std::string Movie::getTitle() const {
	return title_;
}

std::string Movie::getDescription() const {
	return description_;
}

int Movie::getDuration() const {
	return duration_;
}

void Movie::setTitle(const std::string& title) {
	title_ = title;
}

void Movie::setDescription(const std::string& description) {
	description_ = description;
}

void Movie::setDuration(int duration) {
	duration_ = duration;
}

