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
    TitleScreen(ChessGame* gameInstance) : GameScreen(gameInstance) {};

    ~TitleScreen() override;

    // --- Rendering ---
    void renderScreen(SDL_Renderer* renderer, int mouseX, int mouseY) override;

    // --- Resources ---
    void preload() override;

private:
    TTF_Font* titleFont = nullptr;
    TTF_Font* buttonFont = nullptr;
};

#endif // CCHESS_TITLESCREEN_H
