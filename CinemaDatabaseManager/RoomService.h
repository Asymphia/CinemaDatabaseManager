#pragma once

#include "RoomRepository.h"
#include "RoomModel.h"
#include "Service.h"

class RoomService : public Service<Room> {
public:
	explicit RoomService(RoomRepository& repo) : repo_(repo) {}

	bool validate(const Room& r) override;
	std::vector<Room> sort(std::vector<Room> items, const std::string& field, bool ascending = true) override;

	std::vector<Room> getAll();
	std::vector<Room> getByCinemaId(int cinemaId);
	Room getById(int id);
	bool add(const Room& r);
	bool update(const Room& r);
	bool remove(int id);

private:
	RoomRepository& repo_;
};