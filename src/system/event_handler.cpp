#include "system/event_handler.h"

EventHandler::EventHandler(dpp::cluster& bot): bot(bot) {}

void EventHandler::register_events() {
    bot.on_log(dpp::utility::cout_logger());
}
