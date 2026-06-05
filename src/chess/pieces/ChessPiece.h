//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSPIECE_H
#define CCHESS_CHESSPIECE_H
#include <SDL_render.h>
#include <memory>

#include "chess/board/ChessField.h"
#include "chess/model/ChessTeam.h"
#include "chess/moves/ChessMoveSet.h"

class ChessPiece {
public:
    // --- Construction ---
    ChessPiece(std::unique_ptr<ChessMoveSet> moveSet, ChessTeam* team, ChessField* position)
        : moveSet(std::move(moveSet)), team(team), position(position) {};

    virtual ~ChessPiece() = default;

    // --- Movement ---
    virtual bool canMoveTo(ChessField* field);
    virtual void moveTo(ChessField* field) { field->setPiece(this); };

    // --- Capture state ---
    virtual void capturedBy(ChessPiece& piece) { this->isCaptured = true; };

    // --- Rendering ---
    virtual bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize);

private:
    // --- State ---
    bool isCaptured = false;
    std::unique_ptr<ChessMoveSet> moveSet;
    ChessTeam* team;
    ChessField* position;
    SDL_Texture* texture = nullptr;
};

#endif // CCHESS_CHESSPIECE_H
