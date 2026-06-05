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
    void renderScreen(SDL_Renderer* renderer, int mouseX, int mouseY) override;

    // --- Event Handling ---
    void onClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) override;

    // --- Resources ---
    void preload() override;


    private:
};


#endif //CCHESS_PLAYINGSCREEN_H
