#include "MainMenuScreen.hpp"
#include <SDL.h>
#include <iostream>
#include <SDL_opengl.h>
#include "Engine.hpp"
#include "EncounterScreen.hpp"
#include "PlayButton.hpp"
#include "Anchor.hpp"

MainMenuScreen::MainMenuScreen() {
    // Initialize any menu-specific resources here (e.g., load button textures)
    // Create the play button
    PlayButton* playButton = new PlayButton(
    0.0f, 0.0f, 200.0f, 80.0f,
    "Play",
    Anchor::CENTER
    );

    // Set what happens when clicked
    playButton->onClick = [this]() {
        static EncounterScreen encounter;
        encounter.setEngine(engine);
        engine->setScreen(&encounter);
    };

    buttons.push_back(playButton);
}

void MainMenuScreen::update(float dt) {
    // update animations, button hover effects etc.
}

void MainMenuScreen::render() {
    // clear screen for menu
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Play button (simple quad for now)
    for (auto& b : buttons) {
        b->render(engine->getWindowWidth(), engine->getWindowHeight());
    }
}

void MainMenuScreen::handleEvents(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x = event.button.x;
        int y = event.button.y;
        std::cout << "Click at: " << x << "," << y << "\n";
        // Later: check if click inside button bounds

        // Call onClick if hit button
        for(auto& b : buttons) {
            if(b->isClicked(x, y, engine->getWindowWidth(), engine->getWindowHeight())) {
                b->onClick();
            }
        }
    }
}