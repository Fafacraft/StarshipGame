#pragma once
#include "Button.hpp"

class PlayButton : public Button {
public:
    using Button::Button; // inherit constructor

    void render(int windowWidth, int windowHeight) override; 
};