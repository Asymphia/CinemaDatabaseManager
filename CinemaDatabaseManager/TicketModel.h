#pragma once

#include "Model.h"
#include <string>

class Ticket : public Model {
public:
	Ticket() = default;
	Ticket(int id, int scheduleId, int clientId, int ticketTypeId);

	int getId() const override;

	int getScheduleId() const;
	int getClientId() const;
	int getTicketTypeId() const;

	void setScheduleId(int scheduleId);
	void setClientId(int clientId);
	void setTicketTypeId(int ticketTypeId);

private:
	int id_ = 0, scheduleId_ = 0, clientId_ = 0, ticketTypeId_ = 0;
};