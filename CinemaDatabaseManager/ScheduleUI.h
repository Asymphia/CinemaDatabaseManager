#pragma once

#include "ScheduleService.h"
#include "BaseUI.h"

class ScheduleUI : public BaseUI {
public:
	explicit ScheduleUI(ScheduleService& svc) : svc_(svc) {}
	void show() override;

private:
	ScheduleService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Schedule& c);
	void editSchedule(const Schedule& c);
};