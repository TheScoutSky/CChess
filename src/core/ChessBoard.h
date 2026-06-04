//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSBOARD_H
#define CCHESS_CHESSBOARD_H
#include <vector>

#include "ChessField.h"


class ChessBoard {

    public:

    ChessBoard(int width, int height);

    ChessField* getField(int x, int y);
    std::vector<ChessField> board;

private:
    int width, height;



};


#endif //CCHESS_CHESSBOARD_H
