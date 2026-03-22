#pragma once

#include "Database.h"
#include <vector>

template <typename T>
class Repository {
public:
    explicit Repository(Database& db) : db_(db) {}
    virtual ~Repository() = default;

    virtual std::vector<T> getAll() = 0;
    virtual T getById(int id) = 0;

    virtual bool add(const T& entity) = 0;
    virtual bool update(const T& entity) = 0;
    virtual bool remove(int id) = 0;

protected:
    Database& db_;

    static std::string col(PGresult* res, int row, int colIdx);
    static int colInt(PGresult* res, int row, int colIdx);
    static double colDouble(PGresult* res, int row, int colIdx);
};

template <typename T>
std::string Repository<T>::col(PGresult* res, int row, int colIdx) {
    return PQgetvalue(res, row, colIdx);
}

template <typename T>
int Repository<T>::colInt(PGresult* res, int row, int colIdx) {
    return std::stoi(PQgetvalue(res, row, colIdx));
}

template <typename T>
double Repository<T>::colDouble(PGresult* res, int row, int colIdx) {
    return std::stod(PQgetvalue(res, row, colIdx));
}