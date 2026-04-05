#pragma once
#include "Screen.hpp"
#include <SDL.h>

class EncounterScreen : public Screen {
public:
    EncounterScreen() {}
    void update(float dt) override {}
    void render() override;
    void handleEvents(const SDL_Event& event) override;
};