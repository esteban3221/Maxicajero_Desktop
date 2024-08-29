#include "controller/menu/config/informacion_sistema.hpp"
#include "informacion_sistema.hpp"
#ifdef ERROR
#undef ERROR
#endif

ControllerInformacionSistema::ControllerInformacionSistema(/* args */)
{
    this->signal_map().connect(sigc::mem_fun(*this, &ControllerInformacionSistema::onShowWidget));
    this->listAcciones->signal_row_activated().connect(sigc::mem_fun(*this, &ControllerInformacionSistema::onListRowActivate));
}

ControllerInformacionSistema::~ControllerInformacionSistema()
{
}

void ControllerInformacionSistema::onShowWidget()
{
    auto r = cpr::Get(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/configuracion/getInformacionSistema"},
                      cpr::Header{
                          {"Authorization", "Bearer " + Global::Var::token},
                          {"Cookie", "session=" + Global::Var::session}});

    if (r.status_code == 200)
    {
        auto json = nlohmann::json::parse(r.text);

        labels[0]->set_text(json["hostname"].get<std::string>());
        labels[1]->set_text(json["model"].get<std::string>());
        labels[2]->set_text(json["processor"].get<std::string>());
        labels[3]->set_text(json["ram"].get<std::string>());
        labels[4]->set_text(json["memory"].get<std::string>());
    }
    else
    {
        labels[0]->set_text("");
        labels[1]->set_text("");
        labels[2]->set_text("");
        labels[3]->set_text("");
        labels[4]->set_text("");

        Global::Widget::infobar->set_revealed();
        Global::Widget::infobar->set_message_type(Gtk::MessageType::ERROR);

        Global::Widget::lblinfobar->set_text(r.text);
    }
}

void ControllerInformacionSistema::onListRowActivate(Gtk::ListBoxRow *row)
{
    std::string urlBase = "http://" + Global::Var::ipDirection + ":44333/configuracion/";
    cpr::Response r;

    switch (row->get_index())
    {
    case 0:
    {
        r = cpr::Get(cpr::Url{urlBase + "reiniciar"},
                     cpr::Header{
                         {"Authorization", "Bearer " + Global::Var::token},
                         {"Cookie", "session=" + Global::Var::session}});
    }

    break;

    case 1:
    {
        r = cpr::Get(cpr::Url{urlBase + "apagar"},
                     cpr::Header{
                         {"Authorization", "Bearer " + Global::Var::token},
                         {"Cookie", "session=" + Global::Var::session}});
    }
    break;

    default:
        break;
    }

    if (r.status_code == 200)
    {
        Global::Widget::infobar->set_revealed();
        Global::Widget::infobar->set_message_type(Gtk::MessageType::INFO);

        Global::Widget::lblinfobar->set_text("Accion Realizada Exitosamente\nCerrando session...");
        std::thread([this](){
            std::this_thread::sleep_for(std::chrono::seconds(5));
            Global::Widget::btnCerrarSesion->activate();        
            }).detach();
    }
    else
    {
        Global::Widget::infobar->set_revealed();
        Global::Widget::infobar->set_message_type(Gtk::MessageType::ERROR);

        Global::Widget::lblinfobar->set_text(r.text);
    }
}
