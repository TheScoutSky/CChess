//
// Created by Antonio Wil on 30.05.26.
//

#include "chess/moves/ChessMoveSet.h"
#include "chess/moves/ChessMove.h"

// --------------------------------------------------
// Movement Rules
// --------------------------------------------------

bool ChessMoveSet::isMoveAllowed(ChessMove move) {
    std::vector<ChessField*> validFields = getValidMoveFields(move.board, move.from);
    if (std::find(validFields.begin(), validFields.end(), move.to) == validFields.end()) {
        return false;
    }
    return true;
}
std::vector<ChessField*> ChessMoveSet::getValidMoveFields(ChessBoard *board, ChessField *position) {
    std::vector<ChessField*> validFields;
    return validFields;
}
