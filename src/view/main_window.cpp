#include "main_window.hpp"

main_window::main_window(/* args */)
{
    this->set_default_size(800,600);

    Global::Widget::stackMain = &this->stack;
    stack.add(login,"login");
    stack.add(menu,"menu");
    stack.set_transition_type(Gtk::StackTransitionType::ROTATE_LEFT_RIGHT);

    this->set_child(stack);
    this->set_titlebar(*header);

    this->set_title("Maxicajero");
}

main_window::~main_window()
{
}