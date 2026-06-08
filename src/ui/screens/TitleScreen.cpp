//
// Created by Antonio Wil on 04.06.26.
//

#include "ui/screens/TitleScreen.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "app/ChessGame.h"

namespace {
void renderCenteredText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int centerX,
                        int y, SDL_Color color) {
    if (font == nullptr || text == nullptr) {
        return;
    }

    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text, color);
    if (surface == nullptr) {
        std::cerr << "TTF_RenderUTF8_Blended failed: " << TTF_GetError() << '\n';
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << '\n';
        SDL_FreeSurface(surface);
        return;
    }

    int textWidth = 0;
    int textHeight = 0;
    TTF_SizeUTF8(font, text, &textWidth, &textHeight);

    SDL_Rect dstRect = {centerX - textWidth / 2, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
} // namespace

// --------------------------------------------------
// Resources
// --------------------------------------------------

TitleScreen::~TitleScreen() {
    if (titleFont != nullptr) {
        TTF_CloseFont(titleFont);
        titleFont = nullptr;
    }

    if (buttonFont != nullptr) {
        TTF_CloseFont(buttonFont);
        buttonFont = nullptr;
    }
}

void TitleScreen::preload() {
    if (titleFont != nullptr) {
        TTF_CloseFont(titleFont);
    }
    if (buttonFont != nullptr) {
        TTF_CloseFont(buttonFont);
    }

    titleFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 96);
    buttonFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 32);

    if (titleFont == nullptr || buttonFont == nullptr) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << '\n';
        return;
    }
}

// --------------------------------------------------
// Rendering
// --------------------------------------------------

void TitleScreen::renderScreen(SDL_Renderer* renderer, int mouseX, int mouseY) {
    (void)mouseX;
    (void)mouseY;

    int width = 0;
    int height = 0;
    SDL_GetRendererOutputSize(renderer, &width, &height);

    SDL_SetRenderDrawColor(renderer, 14, 18, 28, 255);
    SDL_RenderClear(renderer);

    const int panelWidth = 640;
    const int panelHeight = 600;
    SDL_Rect panel = {width / 2 - panelWidth / 2, height / 2 - panelHeight / 2, panelWidth,
                      panelHeight};
    SDL_SetRenderDrawColor(renderer, 24, 30, 44, 255);
    SDL_RenderFillRect(renderer, &panel);

    SDL_SetRenderDrawColor(renderer, 72, 88, 114, 255);
    SDL_RenderDrawRect(renderer, &panel);

    SDL_Rect inner = {panel.x + 16, panel.y + 16, panel.w - 32, panel.h - 32};
    SDL_SetRenderDrawColor(renderer, 18, 22, 34, 255);
    SDL_RenderFillRect(renderer, &inner);

    SDL_SetRenderDrawColor(renderer, 66, 80, 104, 255);
    SDL_RenderDrawLine(renderer, panel.x + 54, panel.y + 202, panel.x + panel.w - 54,
                       panel.y + 202);

    SDL_Color titleColor = {240, 244, 255, 255};
    SDL_Color subtitleColor = {155, 165, 190, 255};

    renderCenteredText(renderer, titleFont, "CHESS", width / 2, panel.y + 48, titleColor);
    renderCenteredText(renderer, buttonFont, "Clean board. Sharp moves.", width / 2, panel.y + 146,
                       subtitleColor);

    if (buttonFont != nullptr) {
        const int buttonWidth = 400;
        const int buttonHeight = 70;
        const int buttonGap = 18;
        const int buttonX = panel.x + panel.w / 2 - buttonWidth / 2;
        const int buttonY = panel.y + 230;

        CButton startButton = CButton("Start Game", buttonFont,
                                      SDL_Rect{buttonX, buttonY, buttonWidth, buttonHeight});
        startButton.setButtonColor({70, 130, 180, 255});
        startButton.setHoverColor({100, 149, 237, 255});
        startButton.setSelectedColor({120, 170, 245, 255});
        startButton.setOnClick([this]() {
            std::cout << "Start Game button clicked!" << std::endl;
            gameInstance->switchScreen(gameInstance->playingScreen);
        });
        startButton.setTextColor({255, 255, 255});
        addButton("start", startButton);

        CButton optionsButton = CButton(
            "Options", buttonFont,
            SDL_Rect{buttonX, buttonY + buttonHeight + buttonGap, buttonWidth, buttonHeight});
        optionsButton.setButtonColor({52, 63, 82, 255});
        optionsButton.setHoverColor({100, 149, 237, 255});
        optionsButton.setSelectedColor({82, 100, 128, 255});
        optionsButton.setOnClick([]() { std::cout << "Options button clicked!" << std::endl; });
        optionsButton.setTextColor({255, 255, 255});
        addButton("options", optionsButton);

        CButton quitButton = CButton(
            "Quit Game", buttonFont,
            SDL_Rect{buttonX, buttonY + (buttonHeight + buttonGap) * 2, buttonWidth, buttonHeight});
        quitButton.setButtonColor({114, 68, 76, 255});
        quitButton.setHoverColor({100, 149, 237, 255});
        quitButton.setSelectedColor({145, 84, 94, 255});
        quitButton.setOnClick([this]() {
            std::cout << "Quit Game button clicked!" << std::endl;
            gameInstance->quitGame();
        });
        quitButton.setTextColor({255, 255, 255});
        addButton("quit", quitButton);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 14);
    SDL_RenderDrawRect(renderer, &inner);
}
