# Data Model
## Game elements
- **Character Sheet**: Name, Concept, Class, stats, abilities, inventory.
  - **Stats**: 
    - POW (Power)
    - MAG (Magic)
    - HP (health)
    - MP (Mana)
    - DEF (Defense)
    - MDEF (Magic defense)
    - Tier
    - TB (Tier bonus)
    - XP (Experience points)
    - Money
    - TalentSlots (Number of permanent Skills)
    - EQSlots (Number of equipment slots).
  - **Character details**: (These don't have mechanical effects, so just one free-text "description" could suffice. But it still seems like something that'd make sense to split into fields to encourage players to fill them out)
    - Hair
    - Eyes
    - Body build
    - Notable traits
    - Race
    - Origin/Home
    - Age
    - Height
    - Weight
    - Gender
    - Likes
    - Dislikes

- **Player Class**: (Note, "Class" in the RPG sense, not in the OOP sense.) Data about stat progression and starting features. 
  - Shared:
    - Stats on level 1: Tier 1, TalentSlot 0, EQSlot 2.
    - +5HP every level
    - +MP every level
    - +Tier every 5th level
    - +TalentSlot every even level
    - +EQSlot every 5th level
  - Warrior: 
    - Stats on level 1: 6 POW, 4 MAG, 25 HP, 1MP, 11 DEF, 11 MDEF.
    - +POW on odd levels 
    - +MAG every 4th level
    - class skills:
      - MP Haste (Basic attack generates more MP)
      - Physical prowess (Physical abilities cost less MP)
  - Mystic:
    - Stats on level 1: 4 POW, 6 MAG, 20 HP, 3MP, 11 DEF, 11 MDEF.
    - +MAG on odd levels 
    - +POW every 4th level
    - class skills:
      - MP Boost (Additional starting MP)
      - Magical prowess (Magical abilities cost less MP)
  - Guardian:
    - Stats on level 1: 5 POW, 5 MAG, 30 HP, 1MP, 12 DEF, 12 MDEF.
    - +POW every 3rd level 
    - +MAG every 3th level
    - +DEF every 5th level
    - +MDEF every 5th level    
    - class skills:
      - MP Rage (Taking damage generates MP)
      - Defensive prowess (Defensive abilities cost less MP) 

- **Actions**: Behavior a player character can perform. For instance, making a basic attack, moving to a new position, using an item.
  - Type: Basic, Ability, Item, maybe others like movement
  - Economy: Simple, Standard, Complex, free.
  - isDramatic: Whether it can be used when downed.

- **Abilities**: Special attacks, spells, defensive maneuvers et cetera, learned as the character progresses. Name, Category, DefTarget(Whether to-hit is compared to DEF or MDEF, needs a better name), Potency, Element, Tier, Cost, AoE, Range, Extra effect.
  - Arts: 
    - Category for POW-based special attacks. 
    - Used via the "Perform skill" action.
    - These deal damage based on POW and are affected by the warrior's Physical prowess.
  - Spells
    - Category for MAG-based special attacks and other magical effects. 
    - Used via the "Cast a spell" action.
    - These deal damage based on MAG (When applicable) and are affected by the Mystics's Magical prowess.
  - Mobility boosters
    - Category for maneuvers that improve mobility. 
    - (I am actually not sure if they take an action to activate or are just passively active).
  - Defensives
    - Category for maneuvers that affect defensive stats. 
    - Used via a reaction.
    - These reduce damage or increase odds of blocking/evading attacks entirely, and are affected by the Guradian's Defensive prowess.

- **Items**: (Consumable, Equipment, Materials.) Name, description, effects.

- **Status effects**: Negative or positives effects applied via Abilities. 
  - Effects like increasing or lovering stats and causing damage over time. 
  - Each effect might need unique logic.

- **Character Features**: Passive effects. "MP Haste", "MP Boost" and "MP Rage" Are examples of these, all affecting MP, but there are many more. 
  - (Currently called "EQ Skills" in ruleset because most of them come from equipment)

## Game Mechanics
### Combat Flow
- **Initiative**: Determined by 1d20+TB. Combat Manager sorts participants.
- **Turn Resolution**:
  - The turn player decides the order of actions, not the system, so there's no real "phases" to their turn. There are exceptions listed below.
    - Before performing actions, the player writes a roleplaying post, describing what they do. Only after that do they perform game-actions with action economy.
    - Other players can interject in the action economy with their reaction when relevant. (They then describe that interjection in their following roleplaying post on their initiative.)
  - The player can spend their turn's actions in one of these ways (Action economy):
    - 1 Standard action and 2 simple actions.
    - 2 Standard actions.
    - 1 Complex action.
    - (When the player is down to 0HP, they can still act, but instead of the above action economy, they get to do 1 of any action marked "Dramatic")
  - After the turn, resolve effects like taking damage from poison, counting down status durations, etc.
- **Attack resolution**: When performing an action that results in performing an attack, this is the process.
  - Pay MP cost.
  - Roll 1d20 + TB, compare it to target's DEF or MDEF depending on Type of Ability. If the roll is at least as high as the DEF/MDEF, it's a hit. If it's 10 or higher above, it's a critical hit.
  - On a hit, add together Ability's Potency and Player's POW/MAG (depending on Ability). This is the damage.
  - Apply modifiers. (Critical hit increases damage by 50%, some abilities deal less damage in exchange for being AoE or long range etc.)
  - Subtract the modified damage from target's health.
  - Apply special effects of the attack, like inflicting status effects or recovering MP.

### Scene Management
- **Scene States**: 
  - In preperation. GM has an idea, but might be gathering players, asking who is interested etc. (Not something we currently do a lot)
  - Social. Currently just posting activities and dialogues. Post order is less strict and there's no action-economy to enforce.
  - Combat. Participants are currently in combat, taking turns performing game actions.
  - Ended. No more posts allowed. Awaiting grading. (But probably not really enforcable by the bot, so not mechanically "disallowed")
  - Graded. Extended Ended state, but rewards have been given. Scene can be archived safely and moved away from "active" scenes.
  - Hiatus. A scene that is not currently active, but might be revived by it's GM.
- **GM Controls**: Start/end scenes, add and control NPCs, trigger encounters.