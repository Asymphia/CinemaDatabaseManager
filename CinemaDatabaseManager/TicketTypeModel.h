#pragma once

#include "Model.h"

class TicketType : public Model {
public:
	TicketType() = default;
	TicketType(int id, const std::string& type, double price);

	int getId() const override;
	std::string getTableName() const override;
	std::string toString() const override;

	std::string getType() const;
	double getPrice() const;

	void setType(const std::string& type);
	void setPrice(double price);

private:
	int id_ = 0;
	double price_ = 0.0; // TODO: price depends on type
	std::string type_; // TODO: enum for type instead of string
};