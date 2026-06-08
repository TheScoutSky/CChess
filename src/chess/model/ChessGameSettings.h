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
    int fieldSize = 96, boardOffsetX = 576, boardOffsetY = 156;
    int rows = 8, cols = 8;
};

#endif // CCHESS_CHESSGAMESETTINGS_H
