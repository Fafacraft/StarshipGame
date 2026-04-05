#pragma once
#include <vector>
#include "Button.hpp"
#include <SDL.h>

// Forward declaration instead of #include "Engine.hpp" to avoid circular dependency
class Engine;

/// @brief Base class for different game screens (e.g., main menu, gameplay, pause menu)
class Screen {
public:
    virtual ~Screen() = default;

    /// @brief Update game logic / input
    virtual void update(float dt) = 0;

    /// @brief Render to screen
    virtual void render() = 0;

    /// @brief Handle SDL events
    virtual void handleEvents(const SDL_Event& event) {}

    void setEngine(Engine* e) { engine = e; }

protected:
    Engine* engine = nullptr;  // pointer to Engine to control running or switch screens
    std::vector<Button*> buttons;  // list of buttons on this screen (if any)
};