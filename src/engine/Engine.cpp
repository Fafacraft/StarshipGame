#include "Engine.hpp"
#include <iostream>
#include "MainMenuScreen.hpp"
#include <SDL_opengl.h>

// Constructor
Engine::Engine() {}

// When the engine is destroyed, ensure we clean up resources by calling shutdown
Engine::~Engine() {
    shutdown();
}

bool Engine::init(const char* title, int width, int height) {
    std::cout << "Initializing engine...\n";
    // Initialize SDL with video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL Init failed\n";
        return false;
    }

    // Create an SDL window 
    m_window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    if (!m_window) {
        std::cout << "Window creation failed\n";
        return false;
    }

    // Create an OpenGL context associated with the window
    m_glContext = SDL_GL_CreateContext(m_window);

    if (!m_glContext) {
        std::cout << "OpenGL context creation failed\n";
        return false;
    }

    m_running = true;
    std::cout << "Engine initialized successfully\n";
    return true;
}

void Engine::shutdown() {
    // Clean up OpenGL context and window
    if (m_glContext) {
        SDL_GL_DeleteContext(m_glContext);
        m_glContext = nullptr;
    }

    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }

    SDL_Quit();
    std::cout << "Engine shutdown complete\n";
}

void Engine::handleEvents() {
    // Here we will poll for SDL events (like keyboard input, mouse movement, window events, etc.) and handle them accordingly.
    // Create an SDL_Event to hold event data
    if (m_currentScreen) m_currentScreen->handleEvents();
}

void Engine::update(float dt) {
    // Later: ECS systems update here
    // Game logic, physics, AI, etc. will be updated here based on the delta time (dt) since the last frame

    // Update the current screen if it exists
    if (m_currentScreen) m_currentScreen->update(dt);
}

void Engine::render() {
    // Render the current screen if it exists
    if (m_currentScreen) m_currentScreen->render();

    // swap buffers (OpenGL has two buffers - front and back. We render to the back buffer while the front buffer is being displayed, and then swap them to display the new frame)
    SDL_GL_SwapWindow(m_window);
}

bool Engine::isRunning() const {
    return m_running;
}