//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSMOVE_H
#define CCHESS_CHESSMOVE_H
#include "chess/board/ChessField.h"

class ChessBoard;
class ChessPiece;

class ChessMove {
public:
    // --- Construction ---
    ChessMove(ChessBoard* board, ChessPiece* piece, ChessField* from, ChessField* to)
        : piece(piece), from(from), to(to), board(board) {};

    // --- Move data ---
    ChessPiece* piece;
    ChessField *from, *to;
    ChessBoard* board;

private:
};

#endif // CCHESS_CHESSMOVE_H
