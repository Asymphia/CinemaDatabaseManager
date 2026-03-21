#include "TicketModel.h"
#include <sstream>

Ticket::Ticket(int id, int scheduleId, int clientId, int ticketTypeId)
    : id_(id), scheduleId_(scheduleId), clientId_(clientId),
    ticketTypeId_(ticketTypeId) {}

int Ticket::getId() const {
    return id_;
}

std::string Ticket::getTableName() const {
    return "Ticket";
}

std::string Ticket::toString() const {
    std::ostringstream oss;

    oss << "[" << id_ << "]" << " ScheduleId: " << scheduleId_ << " | ClientId: " << clientId_ << " | TypeId: " << ticketTypeId_;

    return oss.str();
}

int Ticket::getScheduleId() const {
    return scheduleId_;
}

int Ticket::getClientId() const {
    return clientId_;
}

int Ticket::getTicketTypeId() const {
    return ticketTypeId_;
}

void Ticket::setScheduleId(int scheduleId) {
    scheduleId_ = scheduleId;
}

void Ticket::setClientId(int clientId) {
    clientId_ = clientId;
}

void Ticket::setTicketTypeId(int ticketTypeId) {
    ticketTypeId_ = ticketTypeId;
}