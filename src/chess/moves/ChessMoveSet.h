//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSMOVESET_H
#define CCHESS_CHESSMOVESET_H
#include "chess/board/ChessBoard.h"
#include "chess/moves/ChessMove.h"

class ChessMoveSet {

    public:
    // --- Movement rules ---
    virtual bool isMoveAllowed(ChessMove move);

    virtual std::vector<ChessField*> getValidMoveFields(ChessBoard* board, ChessField* position);
};

#endif // CCHESS_CHESSMOVESET_H
