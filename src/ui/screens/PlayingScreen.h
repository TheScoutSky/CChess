//
// Created by Antonio Wil on 05.06.26.
//

#ifndef CCHESS_PLAYINGSCREEN_H
#define CCHESS_PLAYINGSCREEN_H
#include "../GameScreen.h"

class PlayingScreen : public GameScreen {

public:
    // --- Construction ---
    PlayingScreen(ChessGame* gameInstance) : GameScreen(gameInstance) {};

    // --- Rendering ---
    void renderScreen(SDL_Renderer* renderer) override;

    // --- Resources ---
    void registerTextures() override;
};


#endif //CCHESS_PLAYINGSCREEN_H
