//
// Created by Antonio Wil on 05.06.26.
//

#include "PlayingScreen.h"

#include <iostream>
#include <ostream>

#include "app/ChessGame.h"

void PlayingScreen::registerTextures() {
    std::cout << "PlayingScreen::registerTextures" << std::endl;
    TTF_Font* buttonFont = TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 36);
    CButton backButton = CButton("Back to Title", buttonFont, SDL_Rect{20, 20, 200, 50});
    backButton.setButtonColor({70, 130, 180, 255});
    backButton.setHoverColor({100, 149, 237, 255});
    backButton.setOnClick([this]() {
        std::cout << "Back to Title button clicked!" << std::endl;
        gameInstance->switchScreen(gameInstance->titleScreen);
    });
    backButton.setTextColor({255, 255, 255});
    addButton("back", backButton);
}

void PlayingScreen::renderScreen(SDL_Renderer *renderer) {
    gameInstance->getBoard()->draw(renderer, 100, 100, gameInstance->getSettings()->fieldSize, gameInstance->getMouseX(), gameInstance->getMouseY());
}
