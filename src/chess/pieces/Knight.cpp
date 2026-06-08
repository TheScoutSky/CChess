//
// Created by Antonio Wil on 08.06.26.
//

#include "Knight.h"
// --------------------------------------------------
// Movement
// --------------------------------------------------

bool KnightMoveSet::isMoveAllowed(ChessMove move) {
    if (move.piece == nullptr || move.from == nullptr || move.to == nullptr) {
        return false;
    }
    int dx = abs(move.to->x - move.from->x);
    int dy = abs(move.to->y - move.from->y);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        return true;
    }
};

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool Knight::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    if (texture == nullptr) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    return true;
}

