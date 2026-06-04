//
// Created by Antonio Wil on 04.06.26.
//

#include "GameScreen.h"

void GameScreen::handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {
    CButton* button = getButtonAt(mouseX, mouseY);
    if (button) {
        button->handleClick(event, mouseX, mouseY);
    }
}

// ----------- Rendering ------------ //

void GameScreen::renderButtons(SDL_Renderer* renderer, int mouseX, int mouseY) {
    for (auto& [name, button] : buttons) {
        bool isHovered = button.isButtonAt(mouseX, mouseY);
        button.renderButton(renderer, isHovered);
    }
}

void GameScreen::renderScreen(SDL_Renderer *renderer) {

}

void GameScreen::registerTextures() {

}
