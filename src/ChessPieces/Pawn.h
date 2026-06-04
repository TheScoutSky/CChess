//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_PAWN_H
#define CCHESS_PAWN_H
#include "../core/interfaces/ChessPiece.h"

class PawnMoveSet: public ChessMoveSet {
    public:
    PawnMoveSet() : ChessMoveSet() { };
    bool isMoveAllowed(ChessMove move) override;


};

class Pawn: public ChessPiece {
    public:
    Pawn(ChessTeam* team, ChessField* position, SDL_Texture* texture) : ChessPiece(std::unique_ptr<PawnMoveSet>(), team, position) {
        this->texture = texture;
    };
    bool draw(SDL_Renderer *renderer, int x, int y, int fieldSize) override;

    private:
    SDL_Texture *texture = nullptr;
};


#endif //CCHESS_PAWN_H
