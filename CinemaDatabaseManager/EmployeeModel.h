#pragma once

#include "Model.h"

class Employee : public Model {
public:
    Employee() = default;
    Employee(int id, int cinemaId, const std::string& name,
        const std::string& surname, const std::string& number,
        const std::string& email);

    int getId() const override;
    std::string getTableName() const override;
    std::string toString() const override;

    int getCinemaId() const;
    std::string getName() const;
    std::string getSurname() const;
    std::string getNumber() const;
    std::string getEmail() const;

    void setCinemaId(int cinemaId);
    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setNumber(const std::string& number);
    void setEmail(const std::string& email);
    
private:
    int id_ = 0, cinemaId_ = 0;
    std::string name_, surname_, number_, email_;
};