#pragma once

#include "Model.h"
#include <string>

class Cinema : public Model {
public:
	Cinema() = default;
	Cinema(int id,
		const std::string& name,
		const std::string& city,
		const std::string& postalCode,
		const std::string& houseNumber);

	int getId() const override;
	std::string getTableName() const override;
	std::string toString() const override;

	std::string getName() const;
	std::string getCity() const;
	std::string getPostalCode() const;
	std::string getHouseNumber() const;

	void setName(const std::string& name);
	void setCity(const std::string& city);
	void setPostalCode(const std::string& postalCode);
	void setHouseNumber(const std::string& houseNumber);

private:
	int id_ = 0;
	std::string name_, city_, postalCode_, houseNumber_;
};