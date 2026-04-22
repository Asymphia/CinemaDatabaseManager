#pragma once

#include "ScheduleService.h"
#include "RoomService.h"
#include "MovieService.h"
#include "BaseUI.h"

class ScheduleUI : public BaseUI {
public:
	explicit ScheduleUI(ScheduleService& svc, RoomService& roomSvc, MovieService& movieSvc) : svc_(svc), roomSvc_(roomSvc), movieSvc_(movieSvc) {}
	void show() override;

private:
	ScheduleService& svc_;
	RoomService& roomSvc_;
	MovieService& movieSvc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Schedule& c);
	void editSchedule(const Schedule& c);

	void getAvailableRooms();
	void getAvailableMovies();
};