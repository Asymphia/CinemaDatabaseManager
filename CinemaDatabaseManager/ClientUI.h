#pragma once

#include "ClientService.h"
#include "TicketService.h"
#include "BaseUI.h"

class ClientUI : public BaseUI {
public:
	explicit ClientUI(ClientService& svc, TicketService& ticketSvc) : svc_(svc), ticketSvc_(ticketSvc) {}
	void show() override;

private:
	ClientService& svc_;
	TicketService& ticketSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Client& c);
	void editClient(const Client& c);
};