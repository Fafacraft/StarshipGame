#pragma once

/// @brief Base class for different game screens (e.g., main menu, gameplay, pause menu)
class Screen {
public:
    virtual ~Screen() = default;

    /// @brief Update game logic / input
    virtual void update(float dt) = 0;

    /// @brief Render to screen
    virtual void render() = 0;

    /// @brief Handle SDL events
    virtual void handleEvents() {}
};