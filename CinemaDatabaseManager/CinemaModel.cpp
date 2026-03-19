#include "CinemaModel.h"
#include <sstream>

Cinema::Cinema(int id,
	const std::string& name,
	const std::string& city,
	const std::string& postalCode,
	const std::string& houseNumber) 
	: id_(id), name_(name), city_(city), postalCode_(postalCode), houseNumber_(houseNumber) {}

int Cinema::getId() const {
	return id_;
}

std::string Cinema::getTableName() const {
	return "Cinema";
}

std::string Cinema::toString() const {
	std::ostringstream oss;

	oss << "[" << id_ << "] " << name_ << " | " << city_ << " " << postalCode_ << " " << houseNumber_;

	return oss.str();
}

std::string Cinema::getName() const {
	return name_;
}

std::string Cinema::getCity() const {
	return city_;
}

std::string Cinema::getPostalCode() const {
	return postalCode_;
}

std::string Cinema::getHouseNumber() const {
	return houseNumber_;
}

void Cinema::setName(const std::string& name) {
	name_ = name;
}

void Cinema::setCity(const std::string& city) {
	city_ = city;
}

void Cinema::setPostalCode(const std::string& postalCode) {
	postalCode_ = postalCode;
}

void Cinema::setHouseNumber(const std::string& houseNumber) {
	houseNumber_ = houseNumber;
}