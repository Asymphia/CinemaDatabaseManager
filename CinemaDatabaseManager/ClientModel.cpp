#include "ClientModel.h"
#include <sstream>

Client::Client(int id, const std::string& name, const std::string& surname,
    const std::string& email, const std::string& number) 
    : id_(id), name_(name), surname_(surname), email_(email), number_(number) {}

int Client::getId() const {
    return id_;
}

std::string Client::getTableName() const {
    return "Client";
}

std::string Client::toString() const {
    std::ostringstream oss;

    oss << "[" << id_ << "] " << name_ << " " << surname_ << " | " << email_ << " | " << number_;

    return oss.str();
}

std::string Client::getName() const {
    return name_;
}

std::string Client::getSurname() const {
    return surname_;
}

std::string Client::getEmail() const {
    return email_;
}

std::string Client::getNumber() const {
    return number_;
}

void Client::setName(const std::string& name) {
    name_ = name;
}

void Client::setSurname(const std::string& surname) {
    surname_ = surname;
}

void Client::setEmail(const std::string& email) {
    email_ = email;
}

void Client::setNumber(const std::string& number) {
    number_ = number;
}