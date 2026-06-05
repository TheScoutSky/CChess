//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSFIELD_H
#define CCHESS_CHESSFIELD_H
#include <SDL_render.h>

#include "chess/model/ChessTeam.h"

class ChessPiece;

class ChessField {

public:
    // --- Board position ---
    int index, x, y;

    // --- Appearance ---
    ChessTeamColor color;

    SDL_Rect rect;

    // --- Construction ---
    ChessField(int index, int x, int y, ChessTeamColor color)
        : index(index), x(x), y(y), color(color) {};

    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, int x, int y, int size, bool isHovered, bool isSelected);

    // --- Piece access ---
    void setPiece(ChessPiece* piece) { this->piece = piece; };

    bool hasPiece() { return this->piece != nullptr; };

    ChessPiece* getPiece() { return this->piece; }

private:
    // --- State ---
    ChessPiece* piece = nullptr;
};

#endif // CCHESS_CHESSFIELD_H
