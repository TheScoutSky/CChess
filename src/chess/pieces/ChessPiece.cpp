//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/ChessPiece.h"
#include <SDL_render.h>

// --------------------------------------------------
// Movement
// --------------------------------------------------

bool ChessPiece::canMoveTo(ChessField* field) {
    ChessMove move = ChessMove(this, position, field);
    return this->moveSet->isMoveAllowed(move);
};

// --------------------------------------------------
// Rendering
// --------------------------------------------------

bool ChessPiece::draw(SDL_Renderer* renderer, int x, int y, int fieldSize) {
    SDL_Texture* texture = this->texture; // falls du eine Textur im Piece speicherst

    if (!texture) {
        return false;
    }

    SDL_Rect dstRect = {x, y, fieldSize, fieldSize};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    return true;
}
