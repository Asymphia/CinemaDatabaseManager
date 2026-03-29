#include "TicketRepository.h"
#include <stdexcept>

std::vector<Ticket> TicketRepository::getAll() {
    PGresult* res = db_.query("SELECT id, scheduleid, clientid, tickettypeid FROM Ticket ORDER BY id");

    std::vector<Ticket> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToTicket(res, i));
    }

    Database::freeResult(res);
    return result;
}

Ticket TicketRepository::getById(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, scheduleid, clientid, tickettypeid FROM Ticket WHERE id=$1", 1, params);

    if (!res || PQntuples(res) == 0) {
        Database::freeResult(res);
        throw std::runtime_error("Ticket not found: id=" + sid);
    }

    Ticket t = rowToTicket(res, 0);
    Database::freeResult(res);
    return t;
}

bool TicketRepository::add(const Ticket& t) {
    std::string sScheduleId = std::to_string(t.getScheduleId());
    std::string sClientId = std::to_string(t.getClientId());
    std::string sTicketTypeId = std::to_string(t.getTicketTypeId());

    const char* params[] = {
        sScheduleId.c_str(),
        sClientId.c_str(),
        sTicketTypeId.c_str()
    };

    PGresult* res = db_.queryParams("INSERT INTO Ticket (scheduleid, clientid, tickettypeid) VALUES ($1,$2,$3)", 3, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool TicketRepository::update(const Ticket& t) {
    std::string sid = std::to_string(t.getId());
    std::string sScheduleId = std::to_string(t.getScheduleId());
    std::string sClientId = std::to_string(t.getClientId());
    std::string sTicketTypeId = std::to_string(t.getTicketTypeId());

    const char* params[] = {
        sScheduleId.c_str(),
        sClientId.c_str(),
        sTicketTypeId.c_str(),
        sid.c_str()
    };

    PGresult* res = db_.queryParams("UPDATE Ticket SET scheduleid=$1, clientid=$2, tickettypeid=$3 WHERE id=$4", 4, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool TicketRepository::remove(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("DELETE FROM Ticket WHERE id=$1", 1, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

std::vector<Ticket> TicketRepository::getByClientId(int clientId) {
    std::string sid = std::to_string(clientId);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, scheduleid, clientid, tickettypeid FROM Ticket WHERE clientid=$1 ORDER BY id", 1, params);

    std::vector<Ticket> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToTicket(res, i));
    }

    Database::freeResult(res);
    return result;
}

std::vector<Ticket> TicketRepository::getByScheduleId(int scheduleId) {
    std::string sid = std::to_string(scheduleId);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, scheduleid, clientid, tickettypeid FROM Ticket WHERE scheduleid=$1 ORDER BY id", 1, params);

    std::vector<Ticket> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToTicket(res, i));
    }

    Database::freeResult(res);
    return result;
}

Ticket TicketRepository::rowToTicket(PGresult* res, int row) {
    return Ticket(
        colInt(res, row, 0),
        colInt(res, row, 1),
        colInt(res, row, 2),
        colInt(res, row, 3)
    );
}