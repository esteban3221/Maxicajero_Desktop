#pragma once
#include "sqlite.hpp"
#include <memory>

class Database
{
private:
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    ~Database() {}

    Database(/* args */)
    {
        this->sqlite3->open();
        if (not this->sqlite3->is_created())
        {
            this->sqlite3->command("CREATE TABLE ipConocidas ("
                                   "id INTEGER PRIMARY KEY,"
                                   "ip TEXT NOT NULL UNIQUE"
                                   ")");
        }
    }

public:
    std::unique_ptr<SQLite3::SQLite> sqlite3 = std::make_unique<SQLite3::SQLite>("unitdb");

    static Database &getInstance()
    {
        static Database instance; // Instancia única de la clase
        return instance;
    }
};