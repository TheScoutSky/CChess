//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_PAWN_H
#define CCHESS_PAWN_H
#include "chess/pieces/ChessPiece.h"

class PawnMoveSet : public ChessMoveSet {
public:
    // --- Construction ---
    PawnMoveSet() : ChessMoveSet() {};

    // --- Movement ---
    bool isMoveAllowed(ChessMove move) override;
};

class Pawn : public ChessPiece {
public:
    // --- Construction ---
    Pawn(ChessTeam* team, ChessField* position, SDL_Texture* texture)
        : ChessPiece(std::unique_ptr<PawnMoveSet>(), team, position) {
        this->texture = texture;
    };

    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;

private:
    // --- State ---
    SDL_Texture* texture = nullptr;
};

#endif // CCHESS_PAWN_H
