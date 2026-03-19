#pragma once

#include "Model.h"

class Room : public Model {
public:
	Room() = default;
	Room(int id, int seatsNum, int cinemaId);

	int getId() const override;
	std::string getTableName() const override;
	std::string toString() const override;

	int getSeatsNum() const;
	int getCinemaId() const;

	void setSeatsNum(int seatsNum);
	void setCinemaId(int cinemaId);

private:
	int id_ = 0, seatsNum_ = 0, cinemaId_ = 0;
};