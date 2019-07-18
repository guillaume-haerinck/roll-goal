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
 * @brief Possible inputs in the game
 */
enum class Inputs {
    MOUSE_DOWN_LEFT,
    MOUSE_DOWN_RIGHT,
    MOUSE_DOWN_MIDDLE,
    MOUSE_SCROLL_UP,
    MOUSE_SCROLL_DOWN,
    MOUSE_MOVE
};

/**
 * @brief Stores action states as booleans, and button bindings to these states
 * @detail Singleton component, only one instance of it through the game
 * 
 * @link https://youtu.be/W3aieHjyNvw?t=715 - Overwatch Gameplay Architecture
 */
namespace scomp {
    struct GameInput {
        std::array<bool, _ACTION_MAX_NUMBER> actionState;
        std::unordered_map<Inputs, Action> buttonBindings;
        glm::vec2 mousePos;
    };
};
