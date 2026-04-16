#pragma once

#include "CinemaService.h"
#include "BaseUI.h"

class CinemaUI : public BaseUI {
public:
	explicit CinemaUI(CinemaService& svc) : svc_(svc) {}
	void show() override;

private:
    CinemaService& svc_;

    void viewAll();
    void addNew();
    void searchById();
    void showDetail(const Cinema& c);
    void editCinema(const Cinema& c);
};