//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/Pawn.h"

// --------------------------------------------------
// Movement
// --------------------------------------------------

bool PawnMoveSet::isMoveAllowed(ChessMove move) {

    return false;
};

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool Pawn::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    if (texture == nullptr) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    return true;
}
