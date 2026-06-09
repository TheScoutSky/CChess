//
// Created by Antonio Wil on 09.06.26.
//

#include "Bishop.h"
// --------------------------------------------------
// Movement
// --------------------------------------------------

std::vector<ChessField*> BishopMoveSet::getValidMoveFields(ChessBoard* board, ChessField* position) {
    std::vector<ChessField*> validFields;

    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (auto& dir : directions) {
        int x = position->x + dir[0];
        int y = position->y + dir[1];

        while (board->isInside(x, y)) {
            ChessField* field = board->getField(x, y);

            if (field->hasPiece()) {
                if (field->getPiece()->team != position->getPiece()->team) {
                    validFields.push_back(field);
                }
                break;
            }

            validFields.push_back(field);
            x += dir[0];
            y += dir[1];
        }
    }

    return validFields;
}

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool Bishop::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    if (texture == nullptr) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    return true;
}

