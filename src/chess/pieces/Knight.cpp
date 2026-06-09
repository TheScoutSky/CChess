//
// Created by Antonio Wil on 08.06.26.
//

#include "Knight.h"
// --------------------------------------------------
// Movement
// --------------------------------------------------

std::vector<ChessField *> KnightMoveSet::getValidMoveFields(ChessBoard *board, ChessField *position) {
    std::vector<ChessField *> validFields;

    int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (auto& move : moves) {
        int x = position->x + move[0];
        int y = position->y + move[1];

        if (board->isInside(x, y)) {
            ChessField* field = board->getField(x, y);

            if (!field->hasPiece() || field->getPiece()->team != position->getPiece()->team) {
                validFields.push_back(field);
            }
        }
    }

    return validFields;
}

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

