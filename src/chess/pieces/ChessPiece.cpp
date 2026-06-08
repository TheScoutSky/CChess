//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/ChessPiece.h"
#include <SDL_render.h>

// --------------------------------------------------
// Movement
// --------------------------------------------------

bool ChessPiece::canMoveTo(ChessField* field) {
    if (field == nullptr || this->position == nullptr || this->moveSet == nullptr) {
        return false;
    }

    ChessMove move(this, position, field);
    return this->moveSet->isMoveAllowed(move);
};

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool ChessPiece::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    if (!this->texture) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, this->texture, nullptr, &dstRect);
    return true;
}
