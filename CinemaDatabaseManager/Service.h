#pragma once

#include <vector>
#include <string>
#include <algorithm>

template <typename T>
class Service {
public:
	virtual ~Service() = default;

	virtual bool validate(const T& entity) = 0;

	virtual std::vector<T> sort(std::vector<T> items, const std::string& sortField, bool ascending = true) = 0;
};