#pragma once

#include "EmployeeRepository.h"
#include "EmployeeModel.h"
#include "Service.h"

class EmployeeService : public Service<Employee> {
public:
	explicit EmployeeService(EmployeeRepository& repo) : repo_(repo) {}

	bool validate(const Employee& e) override;
	std::vector<Employee> sort(std::vector<Employee> items, const std::string& field, bool ascending = true) override;

    std::vector<Employee> getAll();
    std::vector<Employee> getByCinemaId(int cinemaId);
    Employee getById(int id);
    bool add(const Employee& e);
    bool update(const Employee& e);
    bool remove(int id);

private:
    EmployeeRepository& repo_;
};