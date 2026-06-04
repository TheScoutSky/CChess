//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSPIECE_H
#define CCHESS_CHESSPIECE_H
#include <memory>
#include <SDL_render.h>

#include "../ChessField.h"
#include "../logic/ChessMoveSet.h"
#include "../ChessTeam.h"


class ChessPiece {
    public:

    ChessPiece(std::unique_ptr<ChessMoveSet> moveSet, ChessTeam* team, ChessField* position)
        : moveSet(std::move(moveSet)), team(team), position(position) {};

    virtual ~ChessPiece() = default;
    virtual bool canMoveTo(ChessField *field);
    virtual void moveTo(ChessField *field) {
        field->setPiece(this);
    };
    virtual void capturedBy(ChessPiece &piece) {
        this->isCaptured = true;
    };

    virtual bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize);



    private:
    bool isCaptured = false;
    std::unique_ptr<ChessMoveSet> moveSet;
    ChessTeam* team;
    ChessField* position;
    SDL_Texture* texture = nullptr;
};


#endif //CCHESS_CHESSPIECE_H
