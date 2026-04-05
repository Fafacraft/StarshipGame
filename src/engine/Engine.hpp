#pragma once

#include <SDL.h>

class Engine {
public:
    /// Constructor and destructor
    /// Initializes the engine and cleans up resources on destruction
    Engine();
    ~Engine();

    /// @brief Initializes the engine and creates the window
    /// @param title The title of the window
    /// @param width The width of the window
    /// @param height The height of the window
    /// @return True if initialization was successful, false otherwise
    bool init(const char* title, int width, int height);

    /// @brief Shuts down the engine and cleans up resources
    void shutdown();

    /// @brief Handles input events
    void handleEvents();

    /// @brief  Updates the game state
    /// @param dt delta time (time since last frame) in seconds
    void update(float dt);

    /// @brief Renders the current game state to the screen
    void render();

    /// @brief Checks if the engine is still running
    /// @return True if the engine is running, false otherwise
    bool isRunning() const;

private:
    /// @brief Flag to indicate if the engine is running
    bool m_running = false;

    /// @brief Pointer to the SDL window
    SDL_Window* m_window = nullptr;
    /// @brief SDL OpenGL context associated with the window
    SDL_GLContext m_glContext = nullptr;
};