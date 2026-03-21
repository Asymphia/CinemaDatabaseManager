#include "TicketTypeModel.h"
#include <sstream>
#include <iomanip>

TicketType::TicketType(int id, const std::string& type, double price)
	: id_(id), type_(type), price_(price) {}

int TicketType::getId() const {
    return id_;
}

std::string TicketType::getTableName() const {
    return "TicketType";
}

std::string TicketType::toString() const {
    std::ostringstream oss;

    oss << "[" << id_ << "] " << type_ << " | " << std::fixed << std::setprecision(2) << price_ << " z³";

    return oss.str();
}

std::string TicketType::getType() const {
    return type_;
}

double TicketType::getPrice() const {
    return price_;
}

void TicketType::setType(const std::string& type) {
    type_ = type;
}

void TicketType::setPrice(double price) {
    price_ = price;
}