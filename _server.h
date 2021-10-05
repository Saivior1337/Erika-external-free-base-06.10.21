#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "_httplib.h"
using namespace httplib;

#include "json.h"
using json = nlohmann::json;


string bool_to_string(bool state)
{
    return state ? "on" : "off";
}

string page;


void start_server()
{

    std::string line;
    std::ifstream is("index.html");

    if (is.good())
    {
        while (std::getline(is, line))
        {
            page += "\n";
            page += line;
        }
    }
    else
    {
        cout << "Couldn't load index.html!" << endl;
        return;
    }

    Server server;

    server.Get("/toggle", [](const Request& req, Response& res) {
        auto val = req.get_param_value("c");

        if (val == "btn_bhop")
        {
            G.btn_bhop = !G.btn_bhop;
            if (G.btn_bhop)
                std::cout << "bunnyhop activated" << std::endl;
            else
                std::cout << "bunnyhop disabled" << std::endl;
        }

        if (val == "btn_radar")
        {
            G.btn_radar = !G.btn_radar;
            if (G.btn_radar)
                std::cout << "radar activated" << std::endl;
            else
                std::cout << "radar disabled" << std::endl;
        }

        std::this_thread::sleep_for(1ms);
        });

    server.Get("/", [](const Request& req, Response& res) {
        res.set_content(page.c_str(), "text/html");
        });


    server.listen("127.0.0.1", 1001);

    return;
}