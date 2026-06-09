//
// Created by Antonio Wil on 09.06.26.
//

#ifndef CCHESS_BISHOP_H
#define CCHESS_BISHOP_H
#include "Rook.h"
#include "chess/moves/ChessMoveSet.h"


class BishopMoveSet : public ChessMoveSet {
public:
    // --- Construction ---
    BishopMoveSet() : ChessMoveSet() {};

    // --- Movement ---
    std::vector<ChessField *> getValidMoveFields(ChessBoard *board, ChessField *position) override;

    private:
    bool isPathBlocked = false;
};

class Bishop : public ChessPiece {
public:
    // --- Construction ---
    Bishop(ChessTeam* team, ChessField* position, SDL_Texture* texture, ChessBoard* board)
        : ChessPiece(std::make_unique<BishopMoveSet>(), team, position, board) {
        this->texture = texture;
    };


    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;
};


#endif //CCHESS_BISHOP_H
