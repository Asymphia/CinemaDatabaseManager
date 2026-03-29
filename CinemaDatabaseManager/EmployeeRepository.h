#pragma once

#include "Database.h"
#include "EmployeeModel.h"
#include "Repository.h"

class EmployeeRepository : public Repository<Employee> {
public:
	explicit EmployeeRepository(Database& db) : Repository(db) {}

    std::vector<Employee> getAll() override;
    Employee getById(int id) override;
    bool add(const Employee& e) override;
    bool update(const Employee& e) override;
    bool remove(int id) override;

    std::vector<Employee> getByCinemaId(int cinemaId);

private:
    Employee rowToEmployee(PGresult* res, int row);
};