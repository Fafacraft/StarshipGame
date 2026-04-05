#include "Button.hpp"

void Button::render() {
    // Base button does not render anything by default
    // Derived classes should override this to draw the button
}

bool Button::isClicked(float mouseX, float mouseY) {
    return mouseX > (x - width / 2) && mouseX < (x + width / 2) &&
           mouseY > (y - height / 2) && mouseY < (y + height / 2);
}
