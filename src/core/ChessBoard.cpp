//
// Created by Antonio Wil on 30.05.26.
//

#include "ChessBoard.h"

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

ChessField* ChessBoard::getField(int x, int y) {
    return &this->board[y * this->width + x];
}
