#include "controller/menu/config/datos_empresa.hpp"
#include "datos_empresa.hpp"
#ifdef ERROR
#undef ERROR
#endif
ControllerDatosEmpresa::ControllerDatosEmpresa(/* args */) 
{
    this->signal_map().connect(sigc::mem_fun(*this,&ControllerDatosEmpresa::onShowWidget));
    this->btnGuardar->signal_clicked().connect(sigc::mem_fun(*this,&ControllerDatosEmpresa::onBtnGuardarClicked));
}

ControllerDatosEmpresa::~ControllerDatosEmpresa()
{
}

void ControllerDatosEmpresa::onShowWidget()
{
    auto r = cpr::Get(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/configuracion/getInformacion"},
                      cpr::Header{
                          {"Authorization", "Bearer " + Global::Var::token},
                          {"Cookie", "session=" + Global::Var::session}});

    if (r.status_code == 200)
    {
        auto json = nlohmann::json::parse(r.text);

        data[0]->set_text(json["razonSocial"].get<std::string>());
        data[1]->set_text(json["direccion"].get<std::string>());
        data[2]->set_text(json["rfc"].get<std::string>());
        data[3]->set_text(json["contacto"].get<std::string>());
        data[4]->set_text(json["agradecimiento"].get<std::string>());
    }
    else
    {
        data[0]->set_text("");
        data[1]->set_text("");
        data[2]->set_text("");
        data[3]->set_text("");
        data[4]->set_text("");

        Global::Widget::infobar->set_revealed();
        Global::Widget::infobar->set_message_type(Gtk::MessageType::ERROR);

        Global::Widget::lblinfobar->set_text(r.text);
    }
}

void ControllerDatosEmpresa::onBtnGuardarClicked()
{
    nlohmann::json jsonData;
    jsonData["razonSocial"] = data[0]->get_text();
    jsonData["direccion"] = data[1]->get_text();
    jsonData["rfc"] = data[2]->get_text();
    jsonData["contacto"] = data[3]->get_text();
    jsonData["agradecimiento"] = data[4]->get_text();

    auto r = cpr::Post(cpr::Url{"http://" + Global::Var::ipDirection + ":44333/configuracion/actualizaInformacion"},
                      cpr::Header{
                          {"Authorization", "Bearer " + Global::Var::token},
                          {"Cookie", "session=" + Global::Var::session}},
                        cpr::Body(jsonData.dump()));

    Global::Widget::infobar->set_revealed();

    if (r.status_code == 200)
    {
        Global::Widget::infobar->set_message_type(Gtk::MessageType::INFO);

        Global::Widget::lblinfobar->set_text("Se Actualizaron los datos.");
    }
    else
    {
        Global::Widget::infobar->set_message_type(Gtk::MessageType::ERROR);

        Global::Widget::lblinfobar->set_text(r.text);
    }
    
}
