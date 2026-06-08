//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/Pawn.h"

#include <cstdlib>

// --------------------------------------------------
// Movement
// --------------------------------------------------

bool PawnMoveSet::isMoveAllowed(ChessMove move) {
    if (move.piece == nullptr || move.from == nullptr || move.to == nullptr) {
        return false;
    }

        int direction = move.piece->team->color == ChessTeamColor::WHITE ? 1 : -1;
        int startRow = move.piece->team->color == ChessTeamColor::WHITE ? 1 : 6;

        int dx = move.to->x - move.from->x;
        int dy = move.to->y - move.from->y;

        // --- Standard move --- //
        if (dx == 0 && dy == direction && !move.to->hasPiece()) {
            return true;
        }

        // --- Initial double move --- //
        if (dx == 0 && dy == 2 * direction && move.from->y == startRow &&
            !move.to->hasPiece()) {
            return true;
        }

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

