//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSBOARD_H
#define CCHESS_CHESSBOARD_H
#include <vector>

#include "ChessField.h"

class ChessBoard {

public:
    // --- Construction ---
    ChessBoard(ChessGameSettings* settings);

    // --- Field access ---
    ChessField* getField(int x, int y);

    // --- Fields ---
    std::vector<ChessField> board;

    void draw(SDL_Renderer* renderer, int mouseX, int mouseY, ChessField* selectedField);

private:
    // --- Board dimensions ---
    int width, height;
};

#endif // CCHESS_CHESSBOARD_H
