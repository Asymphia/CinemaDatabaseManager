#include "TicketModel.h"
#include <sstream>

Ticket::Ticket(int id, int scheduleId, int clientId, int ticketTypeId)
    : id_(id), scheduleId_(scheduleId), clientId_(clientId),
    ticketTypeId_(ticketTypeId) {}

int Ticket::getId() const {
    return id_;
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