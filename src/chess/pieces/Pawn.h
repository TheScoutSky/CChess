//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_PAWN_H
#define CCHESS_PAWN_H
#include "chess/pieces/ChessPiece.h"
#include <memory>

class PawnMoveSet : public ChessMoveSet {
public:
    // --- Construction ---
    PawnMoveSet() : ChessMoveSet() {};

    // --- Movement ---
    std::vector<ChessField *> getValidMoveFields(ChessBoard *board, ChessField *position) override;
};

class Pawn : public ChessPiece {
public:
    // --- Construction ---
    Pawn(ChessTeam* team, ChessField* position, SDL_Texture* texture, ChessBoard* board)
        : ChessPiece(std::make_unique<PawnMoveSet>(), team, position, board) {
        this->texture = texture;
    };


    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;
};


#endif // CCHESS_PAWN_H
