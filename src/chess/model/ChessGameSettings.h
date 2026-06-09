//
// Created by Antonio Wil on 03.06.26.
//

#ifndef CCHESS_CHESSGAMESETTINGS_H
#define CCHESS_CHESSGAMESETTINGS_H

class ChessGameSettings {

public:
    ChessGameSettings();

    // --- Screen settings --- //
    int screenHeight = 1080, screenWidth = 1920;

    // --- Board settings --- //
    int rows = 8, cols = 8;
    int fieldSize = 88, boardOffsetX = (screenWidth - cols * fieldSize) / 2,
        boardOffsetY = (screenHeight - rows * fieldSize) / 2 - 28;
};

#endif // CCHESS_CHESSGAMESETTINGS_H
