#pragma once

#include "Model.h"

class Movie : public Model {
public:
	Movie() = default;
	Movie(int id, const std::string& title,
		const std::string& description, int duration);

	int getId() const override;
	std::string getTableName() const override;
	std::string toString() const override;

	std::string getTitle() const;
	std::string getDescription() const;
	int getDuration() const;

	void setTitle(const std::string& title);
	void setDescription(const std::string& description);
	void setDuration(int duration);

private:
	int id_ = 0, duration_ = 0;
	std::string title_, description_;
};