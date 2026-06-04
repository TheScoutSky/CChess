//
// Created by Antonio Wil on 04.06.26.
//

#include "../ui/CButton.h"

#include <iostream>


bool CButton::isButtonAt(int x, int y) const {
    return x >= rect.x &&
           x <= rect.x + rect.w &&
           y >= rect.y &&
           y <= rect.y + rect.h;
}

// ------------- Event Handling ---------------- //
void CButton::handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {
        if (event.button == SDL_BUTTON_LEFT) {
            if (mouseX >= rect.x &&
                mouseX <= rect.x + rect.w &&
                mouseY >= rect.y &&
                mouseY <= rect.y + rect.h) {
                isSelected = !isSelected;

                onClick();
            }
        }
}

// ------------- Rendering ----------------- //
void CButton::renderButton(SDL_Renderer *renderer, bool isHovered) const {
    if (isHovered) {
        SDL_SetRenderDrawColor(renderer, hoverColor.r, hoverColor.g, hoverColor.b, hoverColor.a);
    } else if (isSelected) {
        SDL_SetRenderDrawColor(renderer, selectedColor.r, selectedColor.g, selectedColor.b, selectedColor.a);
    } else {
        SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    }

    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 190, 190, 230, 255);
    SDL_RenderDrawRect(renderer, &rect);

    renderText(renderer);

}

void CButton::renderText(SDL_Renderer *renderer) const {
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.c_str(), textColor);

    if (surface == nullptr) {
        std::cerr << "TTF_RenderUTF8_Blended failed: " << TTF_GetError() << '\n';
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << '\n';
        SDL_FreeSurface(surface);
        return;
    }

    int textWidth = 0;
    int textHeight = 0;

    TTF_SizeUTF8(font, text.c_str(), &textWidth, &textHeight);

    int x = rect.x + rect.w / 2 - textWidth / 2;
    int y = rect.y + rect.h / 2 - textHeight / 2;

    SDL_Rect dstRect = {
        x,
        y,
        surface->w,
        surface->h
    };

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
