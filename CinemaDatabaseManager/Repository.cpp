#include "Repository.h"

template <typename T>
std::string Repository<T>::col(PGresult* res, int row, int colIdx) {
    return PQgetvalue(res, row, col);
}

template <typename T>
int Repository<T>::colInt(PGresult* res, int row, int colIdx) {
    return std::stoi(PQgetvalue(res, row, colIdx));
}

template <typename T>
double Repository<T>::colDouble(PGresult* res, int row, int colIdx) {
    return std::stod(PQgetvalue(res, row, colIdx));
}