#pragma once

#include "TicketTypeService.h"
#include "BaseUI.h"

class TicketTypeUI : public BaseUI {
public:
	explicit TicketTypeUI(TicketTypeService& svc) : svc_(svc) {}
	void show() override;

private:
	TicketTypeService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const TicketType& c);
	void editTicketType(const TicketType& c);
};