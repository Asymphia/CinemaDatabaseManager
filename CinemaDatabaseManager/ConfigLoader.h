#pragma once
#include <string>

/* Reading config from .ini file */

class ConfigLoader {
public:
	explicit ConfigLoader(const std::string& filePath = "config.ini");

	std::string getHost() const;
	std::string getPort() const;
	std::string getDbName() const;
	std::string getUser() const;
	std::string getPassword() const;

private:
	std::string host_ = "localhost";
	std::string port_ = "5432";
	std::string dbname_ = "cinema_db";
	std::string user_ = "posgres";
	std::string password_ = "";

	void parse(const std::string& filePath);
	static std::string trim(const std::string& s);
};