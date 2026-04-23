#pragma once

#include "RoomService.h"
#include "CinemaService.h"
#include "BaseUI.h"
#include "ScheduleService.h"

class RoomUI : public BaseUI {
public:
	explicit RoomUI(RoomService& svc, CinemaService& cinemaSvc, ScheduleService& scheduleSvc) : svc_(svc), cinemaSvc_(cinemaSvc), scheduleSvc_(scheduleSvc) {}
	void show() override;

private:
	RoomService& svc_;
	CinemaService& cinemaSvc_;
	ScheduleService& scheduleSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Room& r);
	void editRoom(const Room& r);

	void printAvailableCinemas();
};