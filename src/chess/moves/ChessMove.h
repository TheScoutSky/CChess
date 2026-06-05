//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSMOVE_H
#define CCHESS_CHESSMOVE_H
#include "chess/board/ChessField.h"

class ChessPiece;

class ChessMove {
public:
    // --- Construction ---
    ChessMove(ChessPiece* piece, ChessField* from, ChessField* to)
        : piece(piece), from(from), to(to) {};

    // --- Move data ---
    ChessPiece* piece;
    ChessField *from, *to;

private:
};

#endif // CCHESS_CHESSMOVE_H
