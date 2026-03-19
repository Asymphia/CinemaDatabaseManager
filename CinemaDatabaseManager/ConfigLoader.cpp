#include "ConfigLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

ConfigLoader::ConfigLoader(const std::string& filePath) {
	parse(filePath);
}

std::string ConfigLoader::getHost() const {
	return host_;
}

std::string ConfigLoader::getPort() const {
	return port_;
}

std::string ConfigLoader::getDbName() const {
	return dbname_;
}

std::string ConfigLoader::getUser() const {
	return user_;
}

std::string ConfigLoader::getPassword() const {
	return password_;
}

void ConfigLoader::parse(const std::string& filePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		throw std::runtime_error("Cannot open config file");
	}

	std::string line;

	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#') {
			continue;
		}

		auto pos = line.find('=');

		if (pos == std::string::npos) {
			continue;
		}

		std::string key = trim(line.substr(0, pos));
		std::string value = trim(line.substr(pos + 1));

		if (key == "host") {
			host_ = value;
		}
		else if (key == "port") {
			port_ = value;
		}
		else if (key == "dbname") {
			dbname_ = value;
		}
		else if (key == "user") {
			user_ = value;
		}
		else if (key == "password") {
			password_ = value;
		}
	}
}

std::string ConfigLoader::trim(const std::string& s) {
	const std::string whitespace = " \t\r\n";

	size_t start = s.find_first_not_of(whitespace);

	if (start == std::string::npos) {
		return "";
	}

	size_t end = s.find_last_not_of(whitespace);

	return s.substr(start, end - start + 1);
}