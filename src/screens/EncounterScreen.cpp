#include "EncounterScreen.hpp"
#include "MainMenuScreen.hpp"
#include <SDL_opengl.h>
#include <SDL.h>
#include <iostream>
#include "Engine.hpp"

void EncounterScreen::render() {
    glClearColor(0.0f, 0.1f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // placeholder: green screen
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void EncounterScreen::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            engine->shutdown();  // call shutdown to clean up and exit
        }

        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                // For now, just go back to the menu screen when Escape is pressed
                static MainMenuScreen menu;
                menu.setEngine(engine);
                engine->setScreen(&menu);
            }
        }
    }
}