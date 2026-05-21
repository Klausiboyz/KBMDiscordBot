# Commands

## Player Commands
These allow players to manage their characters and perform actions during scenes.

- `/ping` - Test command (already implemented).
- `/roll <dice>` - Roll dice (e.g., /roll 2d6+3). Used for generic rolls that doesn't already have a command.
- `/create_character` - Starts the character creation process, prompting player to select details one at a time. 
  - Some requested inputs can be left blank (empty string), leaving it up to the player to edit it later. 
  - Steps:
    - Name
    - Class (Warrior, Mystic, Guardian) (Show options and give short description)
    - Choose 3 starting Tier 1 abilities aside from Strike.
    - Choose weapon (equipment)
    - Choose accessory (equipment)
    - Short description (Free text)
- `/set_active_character <character>` - Set the player's active character. If no character is specified on later player commands, the active character is used by default.
- `/view_sheet <character>` - Display the player's current character sheet (stats, abilities, inventory).
- `/edit_sheet <character> <field> <newValue>` - Edit character details (e.g., /edit_sheet name "Example Name" or /edit_sheet description "Example Updated Bio").
- `/level_up <character>` - Apply level-up progression based on player class rules.
  - Can this be an automatic thing that happens when XP is high enough? Would probably need an event system listening on changes to XP value.
- `/inventory` - View Player inventory (Munny, items, quantities, equipped status).
- `/inventory <character>` - View Character inventory (As above, but only things equippen on the character).
- `/equip <character> <item_name>` - Update an empty equipment slot with the id of an item from the inventory with the specified name.
  - If there's no empty slot, or no item in inventory with the specified name, command fails with failure message.
- `/unequip <character> <equipment_slot>` - Clear equipment status in player inventory with item in specified slot, and clears slot.
- `/use_item <character> <item_name>` - Use a consumable item for its instant effect.

- `/perform_action <character> <action_type> [target]` - Perform an action during a scene (e.g., /perform_action ability "Firaga", /perform_action basic "Move", /perform_action item "Potion").
  - Action types: ability (uses AbilityAction), item (uses ItemAction), basic (uses BasicAction).
    - Not to be confused with Simple, Standard and complex. These "types" will just be an economy value in the action data.
  - Transitions to followup-command based on Action_type
- `/view_abilities <character>` - List available abilities for the character.
- `/view_status <character>` - Show current HP, MP, Stat modifications and other effects.
- `/join_scene <character> <scene_name>` - Requests to join a specific scene (The GM who started the scene must accept request)

## GM Commands
These allow Game Masters to manage scenes, NPCs, and encounters.

- `/start_scene <scene_name>` - Begin a new scene (combat or exploration) with participants.
- `/end_scene` - Conclude the current scene.
  - Also lists scene participants for convenience.
  - Might list more data, like post-count, whether or not a combat took place,
- `/grant_rewards <character> <exp_reward> <munny_reward> <item_reward>` - Reward a character after ending a scene.
- `/add_participant <user>` - Add a player or NPC to the current scene.
- `/remove_participant <user>` - Remove a participant from the scene.
- `/initiate_combat <scene_name>` - Start combat mode in the scene, rolling initiative for all participants.
  - I could implement an encounter auto-builder, generating generic enemies based on participating characters. Obviously takes some work.
- `/next_turn` - Advance to the next participant's turn in combat.
  - I might have action check for "bIsMyTurn" or something.
- `/add_npc <name> <class>` - Create and add an NPC character to the scene.
  - Usually an enemy. Class will refer to either Fodder, Elite etc. or "noncombatant", so the system knows not to add it to initiative
- `/generate_encounter <difficulty>` - (WIP/HYPOTHETICAL!) Generate a random encounter with NPCs based on difficulty (TODO more inputs required).
- `/apply_status <target> <status> <duration>` - Apply a status effect to a character (e.g., Poison, Buff).
  - Ideally, this command would only be used for improvised scenarios. Normally, statuses are inflicted by the system via abilities etc.
- `/view_scene` - Display current scene state (participants, initiative order, active effects).

## Admin Commands (WIP)
These are for bot maintenance and configuration.

- `/shutdown` - Gracefully stop the bot.
- `/reload` - Reload configuration or data files.
- `/save_game` - Manually save the current game state to persistent storage.
- `/load_game` - Load a saved game state.
- `/set_role <user> <role>` - Assign a role to a user (Player, GM, Admin).

## Notes
- Commands should use slash commands for better UX in Discord (Is modern Discord standard).
- Target parameters can use @mentions for users or character names.
- Error handling: Commands should validate inputs (e.g., check if character exists, if action is valid in current scene state).
- Permissions: Restrict GM/Admin commands to users with appropriate roles.
- Integration: Commands trigger methods on classes like CharacterSheet::act(), Scene::start(), etc.