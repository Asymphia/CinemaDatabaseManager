#pragma once

#include "TicketService.h"
#include "BaseUI.h"

class TicketUI : public BaseUI {
public:
	explicit TicketUI(TicketService& svc) : svc_(svc) {}
	void show() override;

private:
	TicketService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Ticket& t);
	void editTicket(const Ticket& t);
};