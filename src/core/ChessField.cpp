//
// Created by Antonio Wil on 30.05.26.
//

#include "ChessField.h"

#include "interfaces/ChessPiece.h"

bool ChessField::draw(SDL_Renderer *renderer, int x, int y, int size, bool isHovered, bool isSelected) {
    // ChessField Render Logic

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = size;
    rect.h = size;

    this->rect = rect;

    if (color == WHITE) {
        SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
    }
    SDL_RenderFillRect(renderer, &rect);

    // Draw Hover and Selection Effects
    // enable blending so alpha has an effect
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    if (isSelected) {
        // alpha is 0-255 (10 here is ~4% opacity)
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 10);
        SDL_RenderFillRect(renderer, &rect);
    } else if (isHovered) {
        // use an integer alpha value (51 ~= 20% opacity)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 51);
        SDL_RenderFillRect(renderer, &rect);
    }



    // Render Figure
    if (hasPiece()) {
        getPiece()->draw(renderer, x, y, size);
    }
    return true;
}
