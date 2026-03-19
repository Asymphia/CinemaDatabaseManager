#pragma once

#include <string>
#include <libpq-fe.h>

/* Conneting to PosgreSQL using lipq and making queries */

class Database {
public:
	Database(const std::string& host,
		const std::string& port,
		const std::string& dbname,
		const std::string& user,
		const std::string& password);
	~Database();

	bool connect();
	void disconnect();
	bool isConnected() const;

	PGresult* query(const std::string& sql);
	PGresult* queryParams(const std::string& sql,
		int nParams,
		const char* const* paramValues);

	static void freeResult(PGresult* res);

private:
	PGconn* conn_;
	std::string connStr_;
};