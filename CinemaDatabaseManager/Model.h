#pragma once

class Model {
public:
	virtual ~Model() = default;

	virtual int getId() const = 0;
};