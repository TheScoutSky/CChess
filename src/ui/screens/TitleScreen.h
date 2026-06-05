//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_TITLESCREEN_H
#define CCHESS_TITLESCREEN_H
#include "ui/GameScreen.h"

class ChessGame;

class TitleScreen : public GameScreen {

public:
    // --- Construction ---
    TitleScreen(ChessGame* gameInstance): GameScreen(gameInstance) {};

    // --- Rendering ---
    void renderScreen(SDL_Renderer* renderer) override;

    // --- Resources ---
    void registerTextures() override;
};

#endif // CCHESS_TITLESCREEN_H
