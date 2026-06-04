//
// Created by Antonio Wil on 30.05.26.
//

#include "ChessMove.h"
#include "ChessMoveSet.h"

bool ChessMoveSet::isMoveAllowed(ChessMove move) {
    return move.piece != nullptr;
}
