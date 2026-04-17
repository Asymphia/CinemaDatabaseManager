#pragma once

#include "MovieService.h"
#include "BaseUI.h"

class MovieUI : public BaseUI {
public:
	explicit MovieUI(MovieService& svc) : svc_(svc) {}
	void show() override;

private:
	MovieService& svc_;

	void viewAll();
	void addNew();
	void searchById();
	void showDetail(const Movie& m);
	void editMovie(const Movie& m);
};