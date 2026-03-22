#pragma once

#include "Database.h"
#include <vector>

template <typename T>

class Repository {
public:
	explicit Repository(Database& db) : db_(db) {}
	virtual ~Repository() = default;

	virtual std::vector<T> getAll() = 0;
	virtual T getById() = 0;

	virtual bool add(const T& entity) = 0;
	virtual bool update(const T& entity) = 0;
	virtual bool remove(int id) = 0;

protected:
	Database& db_;

	static std::string col(PGresult* res, int row, int col);
	static int colInt(PGresult* res, int row, int colIdx);
	static double colDouble(PGresult* res, int row, int colIdx);
};