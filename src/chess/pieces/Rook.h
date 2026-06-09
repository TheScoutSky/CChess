//
// Created by Antonio Wil on 08.06.26.
//

#ifndef CCHESS_ROOK_H
#define CCHESS_ROOK_H
#include "ChessPiece.h"


class RookMoveSet : public ChessMoveSet {
public:
    // --- Construction ---
    RookMoveSet() : ChessMoveSet() {};

    // --- Movement ---
    std::vector<ChessField *> getValidMoveFields(ChessBoard *board, ChessField *position) override;

    private:
};

class Rook : public ChessPiece {
public:
    // --- Construction ---
    Rook(ChessTeam* team, ChessField* position, SDL_Texture* texture, ChessBoard* board)
        : ChessPiece(std::make_unique<RookMoveSet>(), team, position, board) {
        this->texture = texture;
    };


    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;
};


#endif //CCHESS_ROOK_H
