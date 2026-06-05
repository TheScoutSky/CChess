//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSMOVESET_H
#define CCHESS_CHESSMOVESET_H
#include "chess/moves/ChessMove.h"

class ChessMoveSet {

public:
    // --- Movement rules ---
    virtual bool isMoveAllowed(ChessMove move);

private:
};

#endif // CCHESS_CHESSMOVESET_H
