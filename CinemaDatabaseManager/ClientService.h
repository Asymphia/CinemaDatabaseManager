#pragma once

#include "ClientRepository.h"
#include "ClientModel.h"
#include "Service.h"

class ClientService : public Service<Client> {
public:
	explicit ClientService(ClientRepository& repo) : repo_(repo) {}

	bool validate(const Client& c) override;

	std::vector<Client> getAll();
	Client getById(int id);
	bool add(const Client& c);
	bool update(const Client& c);
	bool remove(int id);

private:
	ClientRepository& repo_;
};