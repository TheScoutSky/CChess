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

void PlayingScreen::onClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {

     for (auto &field : gameInstance->getBoard()->board) {
         if (field.isClicked(mouseX, mouseY)) {
             if (gameInstance->selectedField) {
                 if (gameInstance->selectedField == &field) {
                     // Deselect current field
                     field.isSelected = false;
                     gameInstance->selectedField = nullptr;
                 } else if (field.hasPiece()) {
                     // Select a different piece
                     gameInstance->selectedField->isSelected = false;
                     field.isSelected = true;
                     gameInstance->selectedField = &field;
                 } else if (gameInstance->selectedField->getPiece()->canMoveTo(&field)) {
                     std::cout << "Moving piece from " << gameInstance->selectedField->x << ", " << gameInstance->selectedField->y
                               << " to " << field.x << ", " << field.y << std::endl;
                     // Move piece to target field
                     gameInstance->selectedField->getPiece()->moveTo(&field);
                     gameInstance->selectedField->isSelected = false;
                     gameInstance->selectedField = nullptr;
                 }
             } else {
                 if (field.hasPiece()) {
                     field.isSelected = true;
                     gameInstance->selectedField = &field;
                 }
             }
             std::cout << "Field " << field.x << ", " << field.y << " clicked. Selected: " << field.isSelected << std::endl;
         }
     }
 }


void PlayingScreen::renderScreen(SDL_Renderer *renderer, int mouseX, int mouseY) {
    gameInstance->getBoard()->draw(renderer, mouseX, mouseY);
}
