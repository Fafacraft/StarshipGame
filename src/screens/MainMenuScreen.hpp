#pragma once
#include "Screen.hpp"

class MainMenuScreen : public Screen {
public:
    MainMenuScreen();
    void update(float dt) override;
    void render() override;
    void handleEvents() override;
};