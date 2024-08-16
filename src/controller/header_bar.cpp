#include "controller/header_bar.hpp"
#include "header_bar.hpp"

namespace Controller
{
    Gtk::ListBoxRow *HeaderBarMain::rowListIp(const std::string &id, const std::string &label)
    {
        auto row = new Gtk::ListBoxRow;
        auto box = new Gtk::Box;
        Gtk::Label labelPrincipal(label);
        auto btnDel = new Gtk::Button;

        box->append(labelPrincipal);
        box->append(*btnDel);

        btnDel->set_image_from_icon_name("list-remove-symbolic");
        btnDel->set_css_classes({"destructive-action"});
        labelPrincipal.set_halign(Gtk::Align::START);
        labelPrincipal.set_hexpand();
        btnDel->set_halign(Gtk::Align::END);

        btnDel->signal_clicked().connect([this, row, id]()
                                         {
            removeIp(id);
            listIpSaves->remove(*row); });

        row->set_child(*box);

        return row;
    }

    HeaderBarMain::HeaderBarMain(/* args */) : isCheckConeccion(false)
    {
        // async
        asyncGui.dispatcher.connect(sigc::mem_fun(asyncGui, &Helper::Async::on_dispatcher_emit));

        // señales
        this->etyDirectionServidor->signal_activate().connect(sigc::mem_fun(*this, &HeaderBarMain::onActiveEntry));
        this->listIpSaves->signal_row_activated().connect(sigc::mem_fun(*this, &HeaderBarMain::onIpRowActivated));
        // init
        initList();
    }

    HeaderBarMain::~HeaderBarMain()
    {
    }

    void HeaderBarMain::onActiveEntry()
    {
        if (isCheckConeccion.load())
            return;

        const auto timeout = std::chrono::seconds(10);
        auto start = std::chrono::steady_clock::now();
        auto end = start + timeout;

        Glib::signal_timeout().connect([this, start, end, timeout]() -> bool
                                       {
                                           auto now = std::chrono::steady_clock::now();
                                           auto remaining = std::chrono::duration_cast<std::chrono::seconds>(end - now).count();
                                           updateProgressIndicator(remaining, timeout.count());
                                           bool status = checkConeccion();
                                            
                                           if (status || remaining <= 0)
                                           {
                                               finalizeConeccion(status);
                                               etyDirectionServidor->set_editable();
                                               return false;
                                           }
                                           return true; }, 100);
    }

    void HeaderBarMain::onIpRowActivated(Gtk::ListBoxRow *row)
    {
        auto box = dynamic_cast<Gtk::Box *>(row->get_child());
        if (box)
        {
            auto labelPrincipal = dynamic_cast<Gtk::Label *>(box->get_children().front());
            Gtk::Button *btnDel = dynamic_cast<Gtk::Button *>(box->get_children().back());
            etyDirectionServidor->set_text(labelPrincipal->get_text());
            btnDel->activate();
            listIpSaves->remove(*row);
            onActiveEntry();
        }
    }

    void HeaderBarMain::updateProgressIndicator(int remaining, int total)
    {

        etyDirectionServidor->set_editable(false);
        static double fraction = 0.0;
        fraction = 1.0 - static_cast<double>(remaining) / total;
        etyDirectionServidor->set_css_classes({"entry"});
        etyDirectionServidor->set_progress_fraction(fraction);
    }

    void HeaderBarMain::finalizeConeccion(bool success)
    {
        asyncGui.dispatch_to_gui([this, success]
                                 {
        if (!success) {
            etyDirectionServidor->set_placeholder_text("No se puede llegar al servidor.");
            //etyDirectionServidor->set_text("");
            etyDirectionServidor->set_css_classes({"error"});
            etyDirectionServidor->set_progress_fraction( 1.0 );
        }
        else
        {
            etyDirectionServidor->set_progress_fraction( 0.0 );
            etyDirectionServidor->set_css_classes({"success"});
            Global::Var::ipDirection = etyDirectionServidor->get_text();
            auto ip = etyDirectionServidor->get_text();
            listIpSaves->prepend(*rowListIp(addIp(ip),ip));
        }
        isinConeccion.store(false);
        isCheckConeccion.store(false); });
    }

    bool HeaderBarMain::checkConeccion()
    {
        auto url = "http://" + etyDirectionServidor->get_text() + ":44333/testConexion";
        cpr::Response r = cpr::Get(cpr::Url{url});
        isinConeccion.store(r.status_code == 200);
        return isinConeccion.load();
    }

    void HeaderBarMain::initList()
    {
        auto List = initData();

        for (size_t i = 0; i < List["id"].size(); i++)
        {
            listIpSaves->prepend(*rowListIp(List["id"][i], List["ip"][i]));
        }

        auto row = listIpSaves->get_row_at_index(0);
        if (row)
        {
            auto box = dynamic_cast<Gtk::Box *>(row->get_child());
            if (box)
            {
                auto labelPrincipal = dynamic_cast<Gtk::Label *>(box->get_children().front());
                //auto btnDel = dynamic_cast<Gtk::Button *>(box->get_children().back());
                etyDirectionServidor->set_text(labelPrincipal->get_text());

                if(checkConeccion())
                {
                    Global::Var::ipDirection = etyDirectionServidor->get_text();
                    etyDirectionServidor->set_css_classes({"success"});
                }
                else
                {
                    etyDirectionServidor->set_css_classes({"error"});
                }
            }
        }
    }
} // namespaces View
