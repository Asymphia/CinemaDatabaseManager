#pragma once

#include "Repository.h"
#include "Database.h"
#include "RoomModel.h"

class RoomRepository : public Repository<Room> {
public:
	explicit RoomRepository(Database& db) : Repository(db) {}

	std::vector<Room> getAll() override;
	Room getById(int id) override;
	bool add(const Room& r) override;
	bool update(const Room& r) override;
	bool remove(int id) override;

	std::vector<Room> getByCinemaId(int cinemaId);

private:
	Room rowToRoom(PGresult* res, int row);
};