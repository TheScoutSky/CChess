//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/pieces/ChessPiece.h"
#include <SDL_render.h>

#include "chess/board/ChessField.h"
#include "chess/model/ChessTeam.h"
#include "chess/moves/ChessMove.h"

// --------------------------------------------------
// Movement
// --------------------------------------------------

bool ChessPiece::canMoveTo(ChessField* field) {
    if (field == nullptr || this->position == nullptr || this->moveSet == nullptr) {
        return false;
    }

    ChessMove move(board, this, position, field);
    return this->moveSet->isMoveAllowed(move);
};

void ChessPiece::moveTo(ChessField *field) {
    position->setPiece(nullptr);
    position = field;

    if (field->hasPiece()) {
        takePiece(field);
    }
    field->setPiece(this);
};


void ChessPiece::takePiece(ChessField* field) {
    this->team->takePiece(field->getPiece());
    field->setPiece(this);
}

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
