//
// Created by Antonio Wil on 05.06.26.
//

#include "PlayingScreen.h"

#include <iostream>
#include <ostream>

#include "app/ChessGame.h"
#include "chess/pieces/ChessPiece.h"

void PlayingScreen::preload() {
    std::cout << "PlayingScreen::preload" << std::endl;
    TTF_Font* buttonFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 28);
    font =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 38);

    const int boardSize =
        gameInstance->getSettings()->fieldSize * gameInstance->getSettings()->cols;
    const int takePanelHeight = gameInstance->getSettings()->fieldSize - 8;
    const int centerX = gameInstance->getSettings()->screenWidth / 2;
    const int buttonWidth = 260;
    const int buttonHeight = 50;
    const int buttonX = centerX - buttonWidth / 2;
    const int buttonY =
        gameInstance->getSettings()->boardOffsetY + boardSize + takePanelHeight + 66;

    CButton backButton =
        CButton("Back to Title", buttonFont, SDL_Rect{buttonX, buttonY, buttonWidth, buttonHeight});
    backButton.setButtonColor({34, 42, 58, 255});
    backButton.setHoverColor({58, 72, 92, 255});
    backButton.setSelectedColor({76, 92, 116, 255});
    backButton.setOnClick([this]() {
        std::cout << "Back to Title button clicked!" << std::endl;
        gameInstance->switchScreen(gameInstance->titleScreen);
    });
    backButton.setTextColor({255, 255, 255});
    addButton("back", backButton);
}

void PlayingScreen::onClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {

    for (auto& field : gameInstance->getBoard()->board) {
        if (field.isClicked(mouseX, mouseY)) {
            if (gameInstance->selectedField) {
                if (gameInstance->selectedField == &field) {
                    // Deselect current field
                    field.isSelected = false;
                    gameInstance->selectedField = nullptr;
                } else if (field.hasPiece() &&
                           field.getPiece()->team == gameInstance->currentTeam) {
                    // Select a different piece
                    gameInstance->selectedField->isSelected = false;
                    field.isSelected = true;
                    gameInstance->selectedField = &field;
                } else if (gameInstance->selectedField->getPiece()->canMoveTo(&field)) {
                    std::cout << "Moving piece from " << gameInstance->selectedField->realX << ", "
                              << gameInstance->selectedField->realY << " to " << field.realX << ", "
                              << field.realY << std::endl;
                    // Move piece to target field
                    gameInstance->selectedField->getPiece()->moveTo(&field);
                    gameInstance->selectedField->isSelected = false;
                    gameInstance->selectedField = nullptr;

                    if (gameInstance->currentTeam == gameInstance->whiteTeam) {
                        gameInstance->currentTeam = gameInstance->blackTeam;
                    } else {
                        gameInstance->currentTeam = gameInstance->whiteTeam;
                    }
                }
            } else {
                if (field.hasPiece() && field.getPiece()->team == gameInstance->currentTeam) {
                    field.isSelected = true;
                    gameInstance->selectedField = &field;
                }
            }
            std::cout << "Field " << field.realX << ", " << field.realY
                      << " clicked. Selected: " << field.isSelected << std::endl;
        }
    }
}

void PlayingScreen::renderScreen(SDL_Renderer* renderer, int mouseX, int mouseY) {
    int width = 0;
    int height = 0;
    SDL_GetRendererOutputSize(renderer, &width, &height);

    SDL_SetRenderDrawColor(renderer, 12, 15, 23, 255);
    SDL_RenderClear(renderer);

    const int boardSize =
        gameInstance->getSettings()->fieldSize * gameInstance->getSettings()->cols;
    const int takePanelHeight = gameInstance->getSettings()->fieldSize - 8;
    const int capturePieceSize = gameInstance->getSettings()->fieldSize - 24;
    const int panelGap = 24;
    const int panelMargin = 18;

    // Panel above board for white Takes
    SDL_Rect whiteTakesRect = {
        gameInstance->getSettings()->boardOffsetX,
        gameInstance->getSettings()->boardOffsetY - takePanelHeight - panelGap,
        boardSize,
        takePanelHeight,
    };

    SDL_SetRenderDrawColor(renderer, 24, 30, 44, 255);
    SDL_RenderFillRect(renderer, &whiteTakesRect);

    SDL_SetRenderDrawColor(renderer, 72, 88, 114, 255);
    SDL_RenderDrawRect(renderer, &whiteTakesRect);

    // Render White takes
    int i = 20;
    for (auto& piece : gameInstance->whiteTeam->getTakenPieces()) {
        piece->draw(renderer, whiteTakesRect.x + i,
                    whiteTakesRect.y + whiteTakesRect.h / 2 - capturePieceSize / 2,
                    capturePieceSize);
        i += capturePieceSize / 2 + 8;
    }

    // Panel under board for black Takes

    SDL_Rect blackTakesRect = {
        gameInstance->getSettings()->boardOffsetX,
        gameInstance->getSettings()->boardOffsetY + boardSize + panelGap,
        boardSize,
        takePanelHeight,
    };

    SDL_SetRenderDrawColor(renderer, 24, 30, 44, 255);
    SDL_RenderFillRect(renderer, &blackTakesRect);

    SDL_SetRenderDrawColor(renderer, 72, 88, 114, 255);
    SDL_RenderDrawRect(renderer, &blackTakesRect);

    // Render Black takes
    i = 20;
    for (auto& piece : gameInstance->blackTeam->getTakenPieces()) {
        piece->draw(renderer, blackTakesRect.x + i,
                    blackTakesRect.y + blackTakesRect.h / 2 - capturePieceSize / 2,
                    capturePieceSize);
        i += capturePieceSize / 2 + 8;
    }

    SDL_Rect boardPanel = {gameInstance->getSettings()->boardOffsetX - panelMargin,
                           gameInstance->getSettings()->boardOffsetY - panelMargin,
                           boardSize + panelMargin * 2, boardSize + panelMargin * 2};

    SDL_SetRenderDrawColor(renderer, 24, 30, 44, 255);
    SDL_RenderFillRect(renderer, &boardPanel);

    SDL_SetRenderDrawColor(renderer, 72, 88, 114, 255);
    SDL_RenderDrawRect(renderer, &boardPanel);

    gameInstance->getBoard()->draw(renderer, mouseX, mouseY, gameInstance->selectedField);

    std::string turnText =
        "Turn: " +
        std::string(gameInstance->currentTeam == gameInstance->whiteTeam ? "White" : "Black");
    int turnTextWidth = 0;
    int turnTextHeight = 0;
    TTF_SizeUTF8(font, turnText.c_str(), &turnTextWidth, &turnTextHeight);

    renderText(renderer, font, turnText.c_str(), width / 2 - turnTextWidth / 2,
               whiteTakesRect.y / 2 - turnTextHeight / 2, {240, 244, 255, 255});
}

void PlayingScreen::renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x,
                               int y, SDL_Color color) {
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

    SDL_Rect dstRect = {x, y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
