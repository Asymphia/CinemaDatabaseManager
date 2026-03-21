#pragma once

#include "Model.h"

class Schedule : public Model {
public:
	Schedule() = default;
	Schedule(int id, int roomId, int movieId,
		const std::string& date, const std::string& time);

	int getId() const override;
	std::string getTableName() const override;
	std::string toString() const override;

	int getRoomId() const;
	int getMovieId() const;
	std::string getDate() const;
	std::string getTime() const;

	void setRoomId(int id);
	void setMovie(int movieId);
	void setDate(const std::string& date);
	void setTime(const std::string& time);

private:
	int id_ = 0, roomId_ = 0, movieId_ = 0;
	std::string date_, time_;
};