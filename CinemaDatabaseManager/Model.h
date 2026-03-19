#pragma once

#include <string>

/* Abstract base class for all models */

class Model {
public:
	virtual ~Model() = default;

	virtual int getId() const = 0;
	virtual std::string toString() const = 0;
	virtual std::string getTableName() const = 0;
};