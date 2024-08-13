#include "main_window.hpp"

main_window::main_window(/* args */)
{
    this->set_default_size(800,600);
    this->set_child(login);
    this->set_titlebar(*header);
}

main_window::~main_window()
{
}