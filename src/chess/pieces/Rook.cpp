//
// Created by Antonio Wil on 08.06.26.
//

#include "Rook.h"
// --------------------------------------------------
// Movement
// --------------------------------------------------

bool RookMoveSet::isMoveAllowed(ChessMove move) {
    if (move.piece == nullptr || move.from == nullptr || move.to == nullptr) {
        return false;
    }
    int dx = move.to->x - move.from->x;
    int dy = move.to->y - move.from->y;

    // Rook Move Set
    if ((dx == 0 && dy != 0) || (dx != 0 && dy == 0)) {
        return true;
    }
    return false;
};

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool Rook::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    if (texture == nullptr) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    return true;
}

