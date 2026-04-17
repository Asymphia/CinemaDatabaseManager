#include "EmployeeRepository.h"
#include <stdexcept>

std::vector<Employee> EmployeeRepository::getAll() {
    PGresult* res = db_.query("SELECT id, cinemaid, name, surname, number, email FROM Employee ORDER BY surname, name");

    std::vector<Employee> result;

    if (!res) {
        return result;
    }

    int rows = PQntuples(res);
    for (int i = 0; i < rows; i++) {
        result.push_back(rowToEmployee(res, i));
    }

    Database::freeResult(res);
    return result;
}

Employee EmployeeRepository::getById(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("SELECT id, cinemaid, name, surname, number, email FROM Employee WHERE id=$1", 1, params);

    if (!res || PQntuples(res) == 0) {
        Database::freeResult(res);
        throw std::runtime_error("Employee not found: id=" + sid);
    }

    Employee e = rowToEmployee(res, 0);
    Database::freeResult(res);
    return e;
}

bool EmployeeRepository::add(const Employee& e) {
    std::string name = e.getName();
    std::string surname = e.getSurname();
    std::string number = e.getNumber();
    std::string email = e.getEmail();

    std::string sCinemaId = std::to_string(e.getCinemaId());

    const char* params[] = {
        sCinemaId.c_str(),
        name.c_str(),
        surname.c_str(),
        number.c_str(),
        email.c_str()
    };

    PGresult* res = db_.queryParams("INSERT INTO Employee (cinemaid, name, surname, number, email) VALUES ($1,$2,$3,$4,$5)", 5, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool EmployeeRepository::update(const Employee& e) {
    std::string name = e.getName();
    std::string surname = e.getSurname();
    std::string number = e.getNumber();
    std::string email = e.getEmail();

    std::string sid = std::to_string(e.getId());
    std::string sCinemaId = std::to_string(e.getCinemaId());

    const char* params[] = {
        sCinemaId.c_str(),
        name.c_str(),
        surname.c_str(),
        number.c_str(),
        email.c_str(),
        sid.c_str()
    };

    PGresult* res = db_.queryParams("UPDATE Employee SET cinemaid=$1, name=$2, surname=$3, number=$4, email=$5 WHERE id=$6", 6, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

bool EmployeeRepository::remove(int id) {
    std::string sid = std::to_string(id);
    const char* params[] = { sid.c_str() };

    PGresult* res = db_.queryParams("DELETE FROM Employee WHERE id=$1", 1, params);

    bool ok = (res != nullptr);
    Database::freeResult(res);
    return ok;
}

Employee EmployeeRepository::rowToEmployee(PGresult* res, int row) {
    return Employee(
        colInt(res, row, 0),
        colInt(res, row, 1),
        col(res, row, 2),
        col(res, row, 3),
        col(res, row, 4),
        col(res, row, 5)
    );
}