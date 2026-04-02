#include <iostream>
#include <cstdlib>
#include <dpp/dpp.h>

int main() {
    // Read Discord token
    const std::string BOT_TOKEN = std::getenv("DISCORD_TOKEN");
    if (BOT_TOKEN.empty()) {
        std::cerr << "Set DISCORD_TOKEN env var\n";
        return 1;
    }

    // Instantiate bot with token
    dpp::cluster bot(BOT_TOKEN);
 
    // Behavior triggered by log-event: forward log entry to console.
    bot.on_log(dpp::utility::cout_logger());
 
    // Behavior triggered by slash commands 
    bot.on_slashcommand([](const dpp::slashcommand_t& event) 
    {
        // define /ping command behavior: reply with "Pong!" in chat
        if (event.command.get_command_name() == "ping") 
        {
            event.reply("Pong!");
        }
    });
 
    // Behavior triggered when the bot is ready
    bot.on_ready([&bot](const dpp::ready_t& event) 
    {
        // run_once ensures ensures no re-registration of commands.
        if (dpp::run_once<struct register_bot_commands>()) 
        {
            // create ping-command in API
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });

    // Start the bot
    bot.start(dpp::st_wait);
}