#pragma once

#include <array>
#include <unordered_map>
#include <glm/vec2.hpp>

/**
 * @brief Possible interactions of the player through his inputs
 * @detail Used as actionState array index so must be continuous
 */
enum Action {
    // In-Game Actions
    ACTION_TILT = 0,

    // Constant used for array size
    _ACTION_MAX_NUMBER
};

/**
 * @brief Stores action states as booleans
 * @description Singleton component, only one instance of it through the game
 * @detail Only modified by game, and read-only otherwise
 * 
 * @link https://youtu.be/W3aieHjyNvw?t=715 - Overwatch Gameplay Architecture
 */
namespace scomp {
    struct GameInput {
        GameInput() : actionState({ false }), mousePos(0.f) {}

        std::array<bool, _ACTION_MAX_NUMBER> actionState;
        glm::vec2 mousePos;
    };
};
