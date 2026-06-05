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
    int index, x, y, size;

    // --- Appearance ---
    ChessTeamColor color;

    SDL_Rect rect;

    // --- Construction ---
    ChessField(int index, int x, int y, int size, ChessTeamColor color)
        : index(index), x(x), y(y), size(size), color(color) {
        SDL_Rect rect = {x, y, size, size};
        this->rect = rect;
    };

    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, bool isHovered);

    // --- Piece access ---
    void setPiece(ChessPiece* piece) { this->piece = piece; };

    bool hasPiece() { return this->piece != nullptr; };

    ChessPiece* getPiece() { return this->piece; }

    // --- Event Handling ---
    bool isClicked(int mouseX, int mouseY) {
        return mouseX >= x && mouseX <= x + size && mouseY >= y && mouseY <= y + size;
    }

    bool isSelected = false;

private:
    // --- State ---
    ChessPiece* piece = nullptr;
};

#endif // CCHESS_CHESSFIELD_H
