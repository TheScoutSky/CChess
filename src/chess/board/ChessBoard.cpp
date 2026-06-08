//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/board/ChessBoard.h"

#include "chess/pieces/ChessPiece.h"

// --------------------------------------------------
// Construction
// --------------------------------------------------

ChessBoard::ChessBoard(ChessGameSettings* settings) {
    this->width = settings->cols;
    this->height = settings->rows;
    this->board.reserve(width * height);

    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ChessTeamColor color = (x + y) % 2 == 0 ? ChessTeamColor::WHITE : ChessTeamColor::BLACK;

            ChessField field = ChessField(i++, x, y, color, settings);
            this->board.push_back(field);
        }
    }
}

// --------------------------------------------------
// Field Access
// --------------------------------------------------

ChessField* ChessBoard::getField(int x, int y) {
    return &this->board[y * this->width + x];
}

// --------------------------------------------------
// Rendering
// --------------------------------------------------

void ChessBoard::draw(SDL_Renderer *renderer, int mouseX, int mouseY, ChessField* selectedField) {
    for (auto chess_field : board) {
        bool isHovered = chess_field.isClicked(mouseX, mouseY);
        bool isHighlighted = (selectedField != nullptr && selectedField->hasPiece() && selectedField->getPiece()->canMoveTo(&chess_field));
        chess_field.draw(renderer, isHovered, isHighlighted);
    }
}
