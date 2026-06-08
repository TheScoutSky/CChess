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

    const int step = move.from->size;
    const int dx = move.to->x - move.from->x;
    const int dy = move.to->y - move.from->y;
    const int direction = (move.piece->team->color == WHITE) ? step : -step;

    if (dx == 0) {
        if (dy == direction && !move.to->hasPiece()) {
            return true;
        }

        // Allow two-field advance if unobstructed target is empty.
        if (dy == 2 * direction && !move.to->hasPiece()) {
            return true;
        }
    }

    if (std::abs(dx) == step && dy == direction && move.to->hasPiece()) {
        return move.to->getPiece()->team->color != move.piece->team->color;
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

bool Pawn::canMoveTo(ChessField* field) {
    return ChessPiece::canMoveTo(field);
}
