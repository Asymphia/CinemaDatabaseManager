#include "Database.h"
#include <iostream>
#include <stdexcept>

Database::Database(const std::string& host,
	const std::string& port,
	const std::string& dbname,
	const std::string& user,
	const std::string& password) : conn_(nullptr) {
	connStr_ = "host=" + host +
		" port=" + port +
		" dbname=" + dbname +
		" user=" + user +
		" password=" + password;
}

Database::~Database() {
	disconnect();
}

bool Database::connect() {
	conn_ = PQconnectdb(connStr_.c_str());

	if (PQstatus(conn_) != CONNECTION_OK) {
		std::cerr << "[Database connection error] " << PQerrorMessage(conn_) << std::endl;

		PQfinish(conn_);
		conn_ = nullptr;

		return false;
	}

	std::cout << "[Database connection] Conected to the database" << std::endl;
	return true;
}

void Database::disconnect() {
	if (conn_) {
		PQfinish(conn_);
		conn_ = nullptr;
	}
}

bool Database::isConnected() const {
	return conn_ != nullptr && PQstatus(conn_) == CONNECTION_OK;
}

PGresult* Database::query(const std::string& sql) {
	if (!isConnected()) {
		throw std::runtime_error("There is no connection to the database");
	}

	PGresult* res = PQexec(conn_, sql.c_str());
	ExecStatusType status = PQresultStatus(res);

	if (status != PGRES_TUPLES_OK && status != PGRES_COMMAND_OK) {
		std::cerr << "[Query error] " << PQresultErrorMessage(res) << std::endl;

		PQclear(res);
		return nullptr;
	}

	return res;
}

PGresult* Database::queryParams(const std::string& sql,
	int nParams,
	const char* const* paramValues) {

	if (!isConnected()) {
		throw std::runtime_error("There is no connection to the database");
	}

	PGresult* res = PQexecParams(conn_, sql.c_str(), nParams, nullptr, paramValues, nullptr, nullptr, 0);
	ExecStatusType status = PQresultStatus(res);

	if (status != PGRES_TUPLES_OK && status != PGRES_COMMAND_OK) {
		std::cerr << "[Query error] " << PQresultErrorMessage(res) << std::endl;

		PQclear(res);
		return nullptr;
	}

	return res;
}

void Database::freeResult(PGresult* res) {
	if (res) {
		PQclear(res);
	}
}