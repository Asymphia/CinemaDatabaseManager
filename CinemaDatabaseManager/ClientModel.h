#pragma once

#include "Model.h"

class Client : public Model {
public:
    Client() = default;
    Client(int id, const std::string& name, const std::string& surname,
        const std::string& email, const std::string& number);

    int getId() const override;
    std::string getTableName() const override;
    std::string toString() const override;

    std::string getName() const;
    std::string getSurname() const;
    std::string getEmail() const;
    std::string getNumber() const;

    void setName(const std::string& name);
    void setSurname(const std::string& surname);
    void setEmail(const std::string& email);
    void setNumber(const std::string& number);

private:
    int id_ = 0;
    std::string name_, surname_, email_, number_;
};