#pragma once

#include "RoomService.h"
#include "CinemaService.h"
#include "BaseUI.h"

class RoomUI : public BaseUI {
public:
	explicit RoomUI(RoomService& svc, CinemaService& cinemaSvc) : svc_(svc), cinemaSvc_(cinemaSvc) {}
	void show() override;

private:
	RoomService& svc_;
	CinemaService& cinemaSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Room& r);
	void editRoom(const Room& r);

	void printAvailableCinemas();
};