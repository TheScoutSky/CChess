//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSFIELD_H
#define CCHESS_CHESSFIELD_H
#include <SDL_render.h>

#include "chess/model/ChessGameSettings.h"
#include "chess/model/ChessTeam.h"

class ChessPiece;

class ChessField {

public:
    // --- Board position ---
    int index, x, y, realX, realY, size;

    // --- Appearance ---
    ChessTeamColor color;

    SDL_Rect rect{};

    // --- Construction ---
    ChessField(int index, int x, int y,ChessTeamColor color, ChessGameSettings* settings)
        : index(index), x(x), y(y), color(color), settings(settings) {

        this->realX = (x * settings->fieldSize) + settings->boardOffsetX;
        this->realY = (y * settings->fieldSize) + settings->boardOffsetY;

        this->size = settings->fieldSize;

        SDL_Rect rect = {realX, realY, size, size};
        this->rect = rect;


    };

    // --- Rendering ---
    bool draw(SDL_Renderer* renderer, bool isHovered, bool isHighlighted);

    // --- Piece access ---
    void setPiece(ChessPiece* piece) { this->piece = piece; };

    bool hasPiece() { return this->piece != nullptr; };

    ChessPiece* getPiece() { return this->piece; }

    // --- Event Handling ---
    bool isClicked(int mouseX, int mouseY) {
        return mouseX >= realX && mouseX <= realX + size && mouseY >= realY && mouseY <= realY + size;
    }

    bool isSelected = false;

private:
    // --- State ---
    ChessPiece* piece = nullptr;
    ChessGameSettings* settings;
};

#endif // CCHESS_CHESSFIELD_H
