#pragma once

#include "TicketTypeService.h"
#include "BaseUI.h"
#include "TicketService.h"

class TicketTypeUI : public BaseUI {
public:
	explicit TicketTypeUI(TicketTypeService& svc, TicketService& ticketSvc) : svc_(svc), ticketSvc_(ticketSvc){}
	void show() override;

private:
	TicketTypeService& svc_;
	TicketService& ticketSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const TicketType& c);
	void editTicketType(const TicketType& c);
};