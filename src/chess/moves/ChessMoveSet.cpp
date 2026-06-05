//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/moves/ChessMoveSet.h"
#include "chess/moves/ChessMove.h"

// --------------------------------------------------
// Movement Rules
// --------------------------------------------------

bool ChessMoveSet::isMoveAllowed(ChessMove move) {
    return move.piece != nullptr;
}
