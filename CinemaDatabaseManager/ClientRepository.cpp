#include "ClientRepository.h"
#include <stdexcept>

std::vector<Client> ClientRepository::getAll() {
    PGresult* res = db_.query("SELECT id, name, surname, email, number FROM Client ORDER BY surname, name");

    std::vector<Client> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToClient(res, i));
    }

    Database::freeResult(res);
    return result;
}

Client ClientRepository::getById(int id) {
    std::string sid = std::to_string(id);

    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, name, surname, email, number FROM Client WHERE id=$1", 1, params);

    if (!res || PQntuples(res) == 0) {
        Database::freeResult(res);
        throw std::runtime_error("Client not found: id=" + sid);
    }

    Client c = rowToClient(res, 0);
    Database::freeResult(res);
    return c;
}

bool ClientRepository::add(const Client& c) {
    const char* params[] = {
        c.getName().c_str(),
        c.getSurname().c_str(),
        c.getEmail().c_str(),
        c.getNumber().c_str()
    };

    PGresult* res = db_.queryParams("INSERT INTO Client (name, surname, email, number) VALUES ($1,$2,$3,$4)", 4, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool ClientRepository::update(const Client& c) {
    std::string sid = std::to_string(c.getId());

    const char* params[] = {
        c.getName().c_str(),
        c.getSurname().c_str(),
        c.getEmail().c_str(),
        c.getNumber().c_str(),
        sid.c_str()
    };

    PGresult* res = db_.queryParams("UPDATE Client SET name=$1, surname=$2, email=$3, number=$4 WHERE id=$5", 5, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool ClientRepository::remove(int id) {
    std::string sid = std::to_string(id);

    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("DELETE FROM Client WHERE id=$1", 1, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

Client ClientRepository::getByEmail(const std::string& email) {
    const char* params[] = { email.c_str() };

    PGresult* res = db_.queryParams("SELECT id, name, surname, email, number FROM Client WHERE email=$1", 1, params);

    if (!res || PQntuples(res) == 0) {
        Database::freeResult(res);
        throw std::runtime_error("Client not found: email=" + email);
    }

    Client c = rowToClient(res, 0);
    Database::freeResult(res);
    return c;
}

Client ClientRepository::rowToClient(PGresult* res, int row) {
    return Client(
        colInt(res, row, 0),
        col(res, row, 1),
        col(res, row, 2),
        col(res, row, 3),
        col(res, row, 4)
    );
}