#include "EmployeeModel.h"
#include <sstream>

Employee::Employee(int id, int cinemaId, const std::string& name,
    const std::string& surname, const std::string& number,
    const std::string& email)
    : id_(id), cinemaId_(cinemaId), name_(name),
    surname_(surname), number_(number), email_(email) {}

int Employee::getId() const {
    return id_;
}

std::string Employee::getTableName() const {
    return "Employee";
}

std::string Employee::toString() const {
    std::ostringstream oss;

    oss << "[" << id_ << "] " << name_ << " " << surname_ << " | " << email_ << " | " << number_ << " | CinemaId: " << cinemaId_;

    return oss.str();
}

int Employee::getCinemaId() const {
    return cinemaId_;
}

std::string Employee::getName() const {
    return name_;
}

std::string Employee::getSurname() const {
    return surname_;
}

std::string Employee::getNumber() const {
    return number_;
}

std::string Employee::getEmail() const {
    return email_;
}

void Employee::setCinemaId(int cinemaId) {
    cinemaId_ = cinemaId;
}

void Employee::setName(const std::string& name) {
    name_ = name;
}

void Employee::setSurname(const std::string& surname) {
    surname_ = surname;
}

void Employee::setNumber(const std::string& number) {
    number_ = number;
}

void Employee::setEmail(const std::string& email) {
    email_ = email;
}