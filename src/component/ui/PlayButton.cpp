#include "PlayButton.hpp"
#include <SDL_opengl.h>

void PlayButton::render() {
    glColor3f(0.2f, 0.2f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}