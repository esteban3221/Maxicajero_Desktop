#pragma once
#include <sqlite3.h>
#include <iostream>
#include <vector>
#include <map>

namespace SQLite3
{
    class SQLite
    {
    private:
        const std::string FILE_DATABASE;
        sqlite3 *db;
        sqlite3_stmt *stmt;
        char *zErrMsg = 0;
        int rc;
        std::string sql;
        static int callback(void *, int, char **, char **);
        static inline std::map<std::string, std::vector<std::string>> result;

    public:
        SQLite(const std::string &DB_);
        ~SQLite();
        const bool open();
        const bool is_created();
        void command(std::string);
        const int get_rc() const;
        std::map<std::string, std::vector<std::string>> &get_result() const;

        template <typename... Args>
        void command(const std::string &sql, Args &&...args)
        {
            result.clear();

            // Compila la sentencia SQL
            sqlite3_stmt *stmt;
            rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, NULL);
            if (rc != SQLITE_OK)
            {
                std::string error = "Error al compilar la sentencia SQL: " + std::string(sqlite3_errmsg(db)) + "\nSQL: " + sql + "\n";
                throw std::runtime_error(error);
            }

            // Bindea los argumentos
            int index = 1;
            (void)std::initializer_list<int>{(bindArgument(stmt, index++, std::forward<Args>(args)), 0)...};

            // Ejecuta la sentencia SQL
            while (sqlite3_step(stmt) == SQLITE_ROW)
            {
                // Callback para procesar los resultados (similar a la función callback)
                int columns = sqlite3_column_count(stmt);
                for (int i = 0; i < columns; i++)
                {
                    const char *columnName = sqlite3_column_name(stmt, i);
                    const char *value = reinterpret_cast<const char *>(sqlite3_column_text(stmt, i));
                    result[columnName].emplace_back(value ? value : "");
                }
            }

            // Finaliza la sentencia
            sqlite3_finalize(stmt);

            if (rc != SQLITE_OK)
            {
                std::string error = "Error al ejecutar la sentencia SQL: " + std::string(sqlite3_errmsg(db)) + "\nSQL: " + sql + "\n";
                throw std::runtime_error(error);
            }
        }

        template <typename T>
        void bindArgument(sqlite3_stmt *stmt, int index, T &&value)
        {
            if constexpr (std::is_integral_v<std::remove_reference_t<T>> || std::is_floating_point_v<std::remove_reference_t<T>>)
            {
                rc = sqlite3_bind_int(stmt, index, value);
            }
            // Exclusivamente tiene que ser const char *
            // else if constexpr (std::is_same_v<std::remove_reference_t<T>, std::string>)
            // {
            //     std::string stringValue = value;
            //     rc = sqlite3_bind_text(stmt, index, stringValue.c_str(), -1, SQLITE_STATIC);
            // }
            else if constexpr (std::is_same_v<std::remove_reference_t<T>, const char *>)
            {
                rc = sqlite3_bind_text(stmt, index, value, -1, SQLITE_STATIC);
            }

            if (rc != SQLITE_OK)
            {
                throw std::runtime_error("Error al bindear el argumento");
            }
        }
    };
} // namespace SQLite3