#pragma once
#include <gtkmm.h>

class Nip : public Gtk::Frame
{
private:
    const char *XML;
protected:


public:
    Gtk::Button *btn[10] = {nullptr};
    Gtk::Box *boxNip = nullptr;
    Gtk::Button *btnNipDel = nullptr;
    Gtk::Button *btnNipEnter = nullptr;
    Gtk::Entry *entry = nullptr;
    
    Nip(/* args */);
    ~Nip();
};


