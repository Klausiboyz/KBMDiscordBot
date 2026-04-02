#pragma once

namespace game {
namespace mechanics {

inline bool can_level_up(int level, int xp) {
    return xp >= (level * 100);
}

} // namespace mechanics
} // namespace game
