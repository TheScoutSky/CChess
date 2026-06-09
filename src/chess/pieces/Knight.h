//
// Created by Antonio Wil on 08.06.26.
//

#ifndef CCHESS_KNIGHT_H
#define CCHESS_KNIGHT_H
#include <memory>
#include <SDL_render.h>

#include "ChessPiece.h"


class KnightMoveSet : public ChessMoveSet {
public:
    // --- Construction ---
    KnightMoveSet() : ChessMoveSet() {};

    // --- Movement ---
    std::vector<ChessField *> getValidMoveFields(ChessBoard *board, ChessField *position) override;
};

class Knight : public ChessPiece {
public:
    // --- Construction ---
    Knight(ChessTeam* team, ChessField* position, SDL_Texture* texture, ChessBoard* board)
        : ChessPiece(std::make_unique<KnightMoveSet>(), team, position, board) {
        this->texture = texture;
    };


    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;
};


#endif //CCHESS_KNIGHT_H
