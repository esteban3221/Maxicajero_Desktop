#include "model/header_bar.hpp"
#include "header_bar.hpp"

namespace Model
{
    HeaderBarMain::HeaderBarMain(/* args */)
    {
    }

    HeaderBarMain::~HeaderBarMain()
    {
    }

    std::string HeaderBarMain::addIp(const std::string &ip)
    {
        Database &database = Database::getInstance();
        database.sqlite3->command("insert into ipConocidas(ip) values (?)", ip.c_str());
        database.sqlite3->command("select id from ipConocidas ORDER BY id DESC LIMIT 1");
        return database.sqlite3->get_result()["id"][0];
    }
    void HeaderBarMain::removeIp(const std::string &id)
    {
        Database &database = Database::getInstance();
        database.sqlite3->command("delete from ipConocidas where id = ?", id.c_str());
    }
    std::map<std::string, std::vector<std::string>> HeaderBarMain::initData()
    {
        Database &database = Database::getInstance();
        database.sqlite3->command("select * from ipConocidas");
        return database.sqlite3->get_result();
    }
} // namespace Model
