#pragma once
#include <string>
#include <functional>
#include "Anchor.hpp"

class Button {
public:
    /// @brief Constructor to initialize button properties
    /// @param offsetX
    /// @param offsetY 
    /// @param width 
    /// @param height 
    /// @param label
    /// @param anchor 
    Button(float offsetX, float offsetY, float width, float height, const std::string& label, Anchor anchor = Anchor::CENTER)
        : offsetX(offsetX), offsetY(offsetY), width(width), height(height), label(label), anchor(anchor)
    {
        // default placeholder function: does nothing
        onClick = [](){};
    }

    /// @brief Renders the button to the screen, to be implemented by derived classes
    virtual void render(int windowWidth, int windowHeight);

    /// @brief Checks if the button was clicked based on mouse coordinates
    /// @param mouseX 
    /// @param mouseY 
    /// @return 
    bool isClicked(float mouseX, float mouseY, float windowWidth, float windowHeight);

    // The action to execute when clicked
    std::function<void()> onClick;

protected:
    float offsetX, offsetY, width, height;
    Anchor anchor;
    std::string label;

    float x, y; // actual position calculated from offset and anchor
    void computePosition(int windowWidth, int windowHeight);
};