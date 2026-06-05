//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/board/ChessBoard.h"

// --------------------------------------------------
// Construction
// --------------------------------------------------

ChessBoard::ChessBoard(int width, int height) {
    this->width = width;
    this->height = height;
    this->board.reserve(width * height);

    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            ChessTeamColor color = (x + y) % 2 == 0 ? ChessTeamColor::WHITE : ChessTeamColor::BLACK;

            ChessField field = ChessField(i++, x, y, color);
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

void ChessBoard::draw(SDL_Renderer *renderer, int xOffset, int yOffset, int fieldSize, int mouseX, int mouseY) {
    for (auto chess_field : board) {
        SDL_Rect fieldRect = {xOffset + chess_field.x * fieldSize,
                              yOffset + chess_field.y * fieldSize, fieldSize, fieldSize};

        bool isHovered = mouseX >= fieldRect.x && mouseX <= fieldRect.x + fieldRect.w &&
                         mouseY >= fieldRect.y && mouseY <= fieldRect.y + fieldRect.h;

        chess_field.draw(renderer, xOffset + chess_field.x * fieldSize,
                         yOffset + chess_field.y * fieldSize, fieldSize, isHovered, false);
    }
}
