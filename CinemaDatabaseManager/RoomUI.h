#pragma once

#include "RoomService.h"
#include "BaseUI.h"

class RoomUI : public BaseUI {
public:
	explicit RoomUI(RoomService& svc) : svc_(svc) {}
	void show() override;

private:
	RoomService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Room& r);
	void editRoom(const Room& r);
};