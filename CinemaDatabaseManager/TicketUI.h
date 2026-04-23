#pragma once

#include "TicketService.h"
#include "BaseUI.h"
#include "ScheduleService.h"
#include "ClientService.h"
#include "TicketTypeService.h"

class TicketUI : public BaseUI {
public:
	explicit TicketUI(TicketService& svc, ScheduleService& scheduleSvc, ClientService& clientSvc, TicketTypeService& ttSvc) : svc_(svc), scheduleSvc_(scheduleSvc), clientSvc_(clientSvc), ttSvc_(ttSvc) {}
	void show() override;

private:
	TicketService& svc_;
	ScheduleService& scheduleSvc_;
	ClientService& clientSvc_;
	TicketTypeService& ttSvc_;

	void viewAll();
	void addNew();
	void showDetail(const Ticket& t);
	void editTicket(const Ticket& t);

	void getAvailableSchedules();
	void getAvailableClients();
	void getAvailableTicketTypes();
};