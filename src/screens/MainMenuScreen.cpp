#include "MainMenuScreen.hpp"
#include <SDL.h>
#include <iostream>
#include <SDL_opengl.h>

MainMenuScreen::MainMenuScreen() {}

void MainMenuScreen::update(float dt) {
    // update animations, button hover effects etc.
}

void MainMenuScreen::render() {
    // clear screen for menu
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Play button (simple quad for now)
    glColor3f(0.8f, 0.8f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.2f, -0.1f);
        glVertex2f(-0.2f, -0.1f);
    glEnd();
}

void MainMenuScreen::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            std::exit(0);  // for now just quit
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x = event.button.x;
            int y = event.button.y;
            std::cout << "Click at: " << x << "," << y << "\n";
            // Later: check if click inside button bounds
        }
    }
}