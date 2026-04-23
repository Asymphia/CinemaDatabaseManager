#pragma once

#include "MovieService.h"
#include "BaseUI.h"
#include "ScheduleService.h"

class MovieUI : public BaseUI {
public:
	explicit MovieUI(MovieService& svc, ScheduleService& scheduleSvc) : svc_(svc), scheduleSvc_(scheduleSvc){}
	void show() override;

private:
	MovieService& svc_;
	ScheduleService& scheduleSvc_;

	void viewAll();
	void addNew();
	void showDetail(const Movie& m);
	void editMovie(const Movie& m);
};