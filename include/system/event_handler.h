#pragma once

#include <dpp/dpp.h>

class EventHandler {
public:
    explicit EventHandler(dpp::cluster& bot);
    void register_events();

private:
    dpp::cluster& bot;
};
