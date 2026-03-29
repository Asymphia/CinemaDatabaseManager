#include "TicketTypeRepository.h"
#include <stdexcept>

std::vector<TicketType> TicketTypeRepository::getAll() {
    PGresult* res = db_.query("SELECT id, type, price FROM TicketType ORDER BY price");

    std::vector<TicketType> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToTicketType(res, i));
    }

    Database::freeResult(res);
    return result;
}

TicketType TicketTypeRepository::getById(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, type, price FROM TicketType WHERE id=$1", 1, params);

    if (!res || PQntuples(res) == 0) {
        Database::freeResult(res);
        throw std::runtime_error("TicketType not found: id=" + sid);
    }

    TicketType tt = rowToTicketType(res, 0);
    Database::freeResult(res);
    return tt;
}

bool TicketTypeRepository::add(const TicketType& tt) {
    std::string sPrice = std::to_string(tt.getPrice());
    const char* params[] = { tt.getType().c_str(), sPrice.c_str() };

    PGresult* res = db_.queryParams("INSERT INTO TicketType (type, price) VALUES ($1,$2)", 2, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool TicketTypeRepository::update(const TicketType& tt) {
    std::string sid = std::to_string(tt.getId());
    std::string sPrice = std::to_string(tt.getPrice());
    const char* params[] = { tt.getType().c_str(), sPrice.c_str(), sid.c_str() };

    PGresult* res = db_.queryParams("UPDATE TicketType SET type=$1, price=$2 WHERE id=$3", 3, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool TicketTypeRepository::remove(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("DELETE FROM TicketType WHERE id=$1", 1, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

TicketType TicketTypeRepository::rowToTicketType(PGresult* res, int row) {
    return TicketType(
        colInt(res, row, 0),
        col(res, row, 1),
        colDouble(res, row, 2)
    );
}