#include <iostream>
#include <cstdlib>
#include <dpp/dpp.h>

#include "system/command_handler.h"
#include "system/event_handler.h"

int main() {
    const char* env_token = std::getenv("DISCORD_TOKEN");
    if (!env_token || env_token[0] == '\0') {
        std::cerr << "Set DISCORD_TOKEN env var\n";
        return 1;
    }

    const std::string BOT_TOKEN(env_token);

    dpp::cluster bot(BOT_TOKEN);

    CommandHandler command_handler(bot);
    EventHandler event_handler(bot);

    event_handler.register_events();
    bot.on_slashcommand([&command_handler](const dpp::slashcommand_t& event) {
        command_handler.on_slash(event);
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
    return 0;
}
