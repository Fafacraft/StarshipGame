#pragma once
#include <string>
#include <functional>

class Button {
public:
    /// @brief Constructor to initialize button properties
    /// @param x 
    /// @param y 
    /// @param width 
    /// @param height 
    /// @param label 
    Button(float x, float y, float width, float height, const char* label)
        : x(x), y(y), width(width), height(height), label(label) 
    {
        // default placeholder function: does nothing
        onClick = [](){};
    }

    /// @brief Renders the button to the screen, to be implemented by derived classes
    virtual void render();

    /// @brief Checks if the button was clicked based on mouse coordinates
    /// @param mouseX 
    /// @param mouseY 
    /// @return 
    bool isClicked(float mouseX, float mouseY);

    // The action to execute when clicked
    std::function<void()> onClick;

protected:
    float x, y, width, height;
    std::string label;
};