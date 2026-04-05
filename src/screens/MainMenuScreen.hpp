#pragma once
#include "Screen.hpp"
#include <SDL.h>

class MainMenuScreen : public Screen {
public:
    MainMenuScreen();
    void update(float dt) override;
    void render() override;
    void handleEvents(const SDL_Event& event) override;
};