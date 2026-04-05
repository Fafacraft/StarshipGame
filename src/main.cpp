#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "engine/Engine.hpp"

int main() {
    // On Windows, SDL redefines main to SDL_main, which can cause issues with our main function.
    SDL_SetMainReady();

    // Initialize the engine and create the window
    Engine engine;
    if (!engine.init("StarshipGame", 800, 600)) {
        return -1;
    }

    // Main game loop
    Uint32 lastTime = SDL_GetTicks();
    while (engine.isRunning()) {
        // Calculate delta time (time since last frame)
        Uint32 currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        // Handle events, update game state, and render
        engine.handleEvents();
        engine.update(dt);
        engine.render();
    }

    // Clean up and exit
    engine.shutdown();
    return 0;
}