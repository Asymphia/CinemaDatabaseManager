#include <iostream>
#include "Database.h"
#include "ConfigLoader.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    ConfigLoader config;

    const std::string host = config.getHost();
    const std::string port = config.getPort();
    const std::string dbname = config.getDbName();
    const std::string user = config.getUser();
    const std::string password = config.getPassword();

    Database db(host, port, dbname, user, password);

    if (!db.connect()) {
        std::cerr << "Error while connecting to the database" << std::endl;
        return 1;
    }


    return 0;
}