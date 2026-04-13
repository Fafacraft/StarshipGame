#include "Button.hpp"

void Button::render(int windowWidth, int windowHeight) {
    // Base button does not render anything by default
    // Derived classes should override this to draw the button
}

bool Button::isClicked(float mouseX, float mouseY, float windowWidth, float windowHeight) {
    computePosition(windowWidth, windowHeight);
    return mouseX > (x - width / 2) && mouseX < (x + width / 2) &&
           mouseY > (y - height / 2) && mouseY < (y + height / 2);
}

void Button::computePosition(int screenW, int screenH) {
    switch (anchor) {
        case Anchor::TOP_LEFT:
            x = offsetX;
            y = offsetY;
            break;

        case Anchor::TOP_CENTER:
            x = screenW / 2.0f + offsetX;
            y = offsetY;
            break;

        case Anchor::TOP_RIGHT:
            x = screenW + offsetX;
            y = offsetY;
            break;

        case Anchor::CENTER:
            x = screenW / 2.0f + offsetX;
            y = screenH / 2.0f + offsetY;
            break;

        case Anchor::BOTTOM_CENTER:
            x = screenW / 2.0f + offsetX;
            y = screenH + offsetY;
            break;

        default:
            x = offsetX;
            y = offsetY;
            break;
    }
}