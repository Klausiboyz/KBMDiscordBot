# Architecture
The bot is structured in C++ using the DPP (Discord++) library. Key components:

## Project Structure
```
cpp-project/
├── src/
│   ├── main.cpp              # Entry point only
│   ├── system/               # Logic to tie things together (all the bot-logic)
│   │   ├── event_handler.cpp
│   │   └── command_handler.cpp
│   └── game_elements/        # Logic representing the actual game rules and objects
│       ├── game_objects/
│       │   ├── items.cpp
│       │   └── character_sheet.cpp
│       └── game_mechanics/
│           ├── abilities.cpp
│           └── level_up.cpp
├── include/
│   ├── system/
│   │   ├── ping_command.h
│   │   └── command_handler.h
│   └── game_elements/
│       └── (...)
├── CMakeLists.txt
└── build/
```

## Core Modules
- **Command Handler**: Parses and executes user commands.
- **Event Handler**: Manages Discord events (messages, reactions, etc.).
- **Game Elements**: Encapsulates game logic (characters, items, mechanics).
- **Data Layer**: Handles storage and retrieval of game data.