//
// Created by Antonio Wil on 04.06.26.
//

#include "ui/screens/TitleScreen.h"

#include <iostream>

#include "app/ChessGame.h"

// --------------------------------------------------
// Resources
// --------------------------------------------------

void TitleScreen::registerTextures() {
    TTF_Font* titleFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 96);
    TTF_Font* buttonFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 36);

    if (titleFont == nullptr || buttonFont == nullptr) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << '\n';
    }

    CButton startButton = CButton("Start Game", buttonFont, SDL_Rect{740, 400, 500, 80});
    startButton.setButtonColor({70, 130, 180, 255});
    startButton.setHoverColor({100, 149, 237, 255});
    // When Start is clicked, switch to the playing screen (not back to the title screen).
    startButton.setOnClick([this]() {
        std::cout << "Start Game button clicked!" << std::endl;
        gameInstance->switchScreen(gameInstance->playingScreen);
    });
    startButton.setTextColor({255, 255, 255});
    addButton("start", startButton);

    CButton optionsButton = CButton("Options", buttonFont, SDL_Rect{740, 500, 500, 80});
    optionsButton.setButtonColor({70, 130, 180, 255});
    optionsButton.setHoverColor({100, 149, 237, 255});
    optionsButton.setOnClick([]() { std::cout << "Options button clicked!" << std::endl; });
    optionsButton.setTextColor({255, 255, 255});
    addButton("options", optionsButton);

    CButton quitButton = CButton("Quit Game", buttonFont, SDL_Rect{740, 600, 500, 80});
    quitButton.setButtonColor({70, 130, 180, 255});
    quitButton.setHoverColor({100, 149, 237, 255});
    quitButton.setOnClick([this]() {
        std::cout << "Quit Game button clicked!" << std::endl;
        gameInstance->quitGame();
    });
    quitButton.setTextColor({255, 255, 255});
    addButton("quit", quitButton);
}

// --------------------------------------------------
// Rendering
// --------------------------------------------------

void TitleScreen::renderScreen(SDL_Renderer* renderer) {
}
