#include "sqlite.hpp"
#include <fstream>

namespace SQLite3
{
    SQLite::SQLite(const std::string &file_database_) : FILE_DATABASE(file_database_) , db(nullptr)
    {
    }

    SQLite::~SQLite()
    {
        sqlite3_close(this->db);
    }

    const bool SQLite::open()
    {
        this->rc = sqlite3_open(this->FILE_DATABASE.c_str(), &this->db);
        if (this->rc)
        {
            std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(this->db) << std::endl;
            return false;
        }
        else
            return true;
    }

    const bool SQLite::is_created()
    {
        command("SELECT name FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%'");
        return not get_result().empty();
    }

    int SQLite::callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        for (size_t i = 0; i < argc; i++)
        {
            result[azColName[i]].emplace_back(argv[i] ? argv[i] : "");
        }
        return 0;
    }

    void SQLite::command(std::string sql)
    {
        result.clear();
        this->rc = sqlite3_exec(this->db, sql.c_str(), callback, 0, &zErrMsg);
        if (this->rc != SQLITE_OK)
        {
            std::string error = "SQL error: " + std::string(zErrMsg) + "\nSQL: " + sql + "\n";
            sqlite3_free(zErrMsg);
            throw std::runtime_error(error);
        }
    }
    
    std::map<std::string, std::vector<std::string>> &SQLite::get_result() const
    {
        return result;
    }

    const int SQLite::get_rc() const
    {
        return this->rc;
    }
}