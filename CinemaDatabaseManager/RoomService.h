#pragma once

#include "RoomRepository.h"
#include "RoomModel.h"
#include "Service.h"

class RoomService : public Service<Room> {
public:
	explicit RoomService(RoomRepository& repo) : repo_(repo) {}

	bool validate(const Room& r) override;

	std::vector<Room> getAll();
	Room getById(int id);
	bool add(const Room& r);
	bool update(const Room& r);
	bool remove(int id);

	std::vector<Room> getByCinemaId(int cinemaId);

private:
	RoomRepository& repo_;
};