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
    bool isMoveAllowed(ChessMove move) override;
};

class Knight : public ChessPiece {
public:
    // --- Construction ---
    Knight(ChessTeam* team, ChessField* position, SDL_Texture* texture)
        : ChessPiece(std::make_unique<KnightMoveSet>(), team, position) {
        this->texture = texture;
    };


    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize) override;
};


#endif //CCHESS_KNIGHT_H
