#pragma once

#include "ClientModel.h"
#include "Database.h"
#include "Repository.h"

class ClientRepository : public Repository<Client> {
public:
	explicit ClientRepository(Database& db) : Repository(db) {}

	std::vector<Client> getAll() override;
	Client getById(int id) override;
	bool add(const Client& c) override;
	bool update(const Client& c) override;
	bool remove(int id) override;

	Client getByEmail(const std::string& email);

private:
	Client rowToClient(PGresult* res, int row);
};