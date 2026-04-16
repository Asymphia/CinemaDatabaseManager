#pragma once

#include "CinemaService.h"

class CinemaUI {
public:
	explicit CinemaUI(CinemaService& svc) : svc_(svc) {}
	void show();

private:
    CinemaService& svc_;

    void viewAll();
    void addNew();
    void searchById();
    void showDetail(const Cinema& c);
    void editCinema(const Cinema& c);
};