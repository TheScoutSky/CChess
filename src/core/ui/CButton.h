//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_CBUTTON_H
#define CCHESS_CBUTTON_H
#include <functional>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <string>
#include <utility>


class CButton {
    public:
    CButton(std::string text, TTF_Font* font, SDL_Rect rect)
        : text(std::move(text)), rect(rect), font(font) {};

    // --- Setters --- //
    void setTextColor(SDL_Color textColor) {
        this->textColor = textColor;
    }

    void setHoverColor(SDL_Color hoverColor) {
        this->hoverColor = hoverColor;
    }

    void setSelectedColor(SDL_Color selectedColor) {
        this->selectedColor = selectedColor;
    }

    void setButtonColor(SDL_Color buttonColor) {
        this->buttonColor = buttonColor;
    }

    void setOnClick(std::function<void()> onClick) {
        this->onClick = std::move(onClick);
    }

    // --- Rendering ---//
    void renderButton(SDL_Renderer *renderer, bool isHovered);

    private:

    // --- Event Handling --- //
    void handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY);

    // --- Rendering --- //
    void renderText(SDL_Renderer *renderer) const;

    // --- Variables --- //
    bool isSelected{};
    std::function<void()> onClick{};

    std::string text;
    SDL_Rect rect;
    TTF_Font* font;

    SDL_Color textColor{};
    SDL_Color buttonColor{};
    SDL_Color hoverColor{};
    SDL_Color selectedColor{};


};


#endif //CCHESS_CBUTTON_H
