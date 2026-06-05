//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/board/ChessField.h"

#include "chess/pieces/ChessPiece.h"

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool ChessField::draw(SDL_Renderer* renderer, bool isHovered) {
    // --- Field rectangle ---

    // --- Base field color ---
    if (color == WHITE) {
        SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
    }
    SDL_RenderFillRect(renderer, &rect);

    // --- Hover and selection overlays ---
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    if (isSelected) {
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 50);
        SDL_RenderFillRect(renderer, &rect);
    } else if (isHovered) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 51);
        SDL_RenderFillRect(renderer, &rect);
    }

    // --- Piece rendering ---
    if (hasPiece()) {
        getPiece()->draw(renderer, x, y, size);
    }
    return true;
}
