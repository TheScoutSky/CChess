//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/board/ChessBoard.h"

// --------------------------------------------------
// Construction
// --------------------------------------------------

ChessBoard::ChessBoard(int width, int height, int fieldSize, int xOffset, int yOffset) {
    this->width = width;
    this->height = height;
    this->board.reserve(width * height);

    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ChessTeamColor color = (x + y) % 2 == 0 ? ChessTeamColor::WHITE : ChessTeamColor::BLACK;

            ChessField field = ChessField(i++, (x * fieldSize) + xOffset, (y * fieldSize) + yOffset, fieldSize, color);
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

void ChessBoard::draw(SDL_Renderer *renderer, int mouseX, int mouseY) {
    for (auto chess_field : board) {
        bool isHovered = chess_field.isClicked(mouseX, mouseY);

        chess_field.draw(renderer, isHovered);
    }
}
