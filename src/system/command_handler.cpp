#include "system/command_handler.h"

CommandHandler::CommandHandler(dpp::cluster& bot): bot(bot) {}

void CommandHandler::register_commands() {
    // Example command registration can go here
}

void CommandHandler::on_slash(const dpp::slashcommand_t& event) {
    if (event.command.get_command_name() == "ping") {
        event.reply("Pong!");
    }
}
