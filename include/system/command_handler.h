#pragma once

#include <dpp/dpp.h>

class CommandHandler {
public:
    explicit CommandHandler(dpp::cluster& bot);
    void register_commands();
    void on_slash(const dpp::slashcommand_t& event);

private:
    dpp::cluster& bot;
};
