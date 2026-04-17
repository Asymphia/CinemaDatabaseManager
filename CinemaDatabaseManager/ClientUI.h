#pragma once

#include "ClientService.h"
#include "BaseUI.h"

class ClientUI : public BaseUI {
public:
	explicit ClientUI(ClientService& svc) : svc_(svc) {}
	void show() override;

private:
	ClientService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Client& c);
	void editClient(const Client& c);
};