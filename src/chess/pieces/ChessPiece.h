//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSPIECE_H
#define CCHESS_CHESSPIECE_H
#include <SDL_render.h>
#include <memory>

#include "chess/moves/ChessMoveSet.h"

class ChessField;
class ChessTeam;
class ChessBoard;

class ChessPiece {
public:
    // --- Construction ---
    ChessPiece(std::unique_ptr<ChessMoveSet> moveSet, ChessTeam* team, ChessField* position, ChessBoard* board)
        : moveSet(std::move(moveSet)), team(team), position(position), board(board) {

    };

    virtual ~ChessPiece() = default;

    // --- Movement ---
    virtual bool canMoveTo(ChessField* field);
    virtual void moveTo(ChessField* field);
    virtual void takePiece(ChessField* field);

    // --- Capture state ---
    virtual void capturedBy(ChessPiece& piece) { this->isCaptured = true; };

    // --- Rendering ---
     virtual bool draw(SDL_Renderer* renderer, int x, int y, int fieldSize);

    ChessTeam* team;

 protected:
     // --- State ---
     SDL_Texture* texture = nullptr;
     ChessBoard* board;

 private:
     // --- State ---
     bool isCaptured = false;
     std::unique_ptr<ChessMoveSet> moveSet;
     ChessField* position;
};

#endif // CCHESS_CHESSPIECE_H
