#pragma once
#include "Screen.hpp"

class EncounterScreen : public Screen {
public:
    EncounterScreen() {}
    void update(float dt) override {}
    void render() override;
    void handleEvents() override;
};