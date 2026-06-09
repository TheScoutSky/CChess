//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/Pawn.h"

#include <cstdlib>

// --------------------------------------------------
// Movement
// --------------------------------------------------

std::vector<ChessField *> PawnMoveSet::getValidMoveFields(ChessBoard *board, ChessField *position) {
    std::vector<ChessField *> validFields;

    int direction = position->getPiece()->team->color == WHITE ? 1 : -1;
    int startRow = position->getPiece()->team->color == WHITE ? 1 : 6;

    // Move forward
    int x = position->x;
    int y = position->y + direction;

    if (board->isInside(x, y) && !board->getField(x, y)->hasPiece()) {
        validFields.push_back(board->getField(x, y));

        // Move two squares from starting position
        if (position->y == startRow) {
            y += direction;
            if (board->isInside(x, y) && !board->getField(x, y)->hasPiece()) {
                validFields.push_back(board->getField(x, y));
            }
        }
    }

    // Capture diagonally
    for (int dx : {-1, 1}) {
        x = position->x + dx;
        y = position->y + direction;

        if (board->isInside(x, y) && board->getField(x, y)->hasPiece() &&
            board->getField(x, y)->getPiece()->team != position->getPiece()->team) {
            validFields.push_back(board->getField(x, y));
        }
    }

    return validFields;
}

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

