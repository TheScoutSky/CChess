//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_GAMESCREEN_H
#define CCHESS_GAMESCREEN_H
#include <SDL_events.h>
#include <string>
#include <unordered_map>

#include "ui/CButton.h"

class ChessGame;

class GameScreen {

public:
    // --- Lifecycle ---
    GameScreen(ChessGame* gameInstance) : gameInstance(gameInstance) {};
    virtual ~GameScreen() = default;

    // --- Resources ---
    virtual void preload();

    // --- Buttons ---
    void addButton(const std::string& name, const CButton& button) {
        buttons.erase(name);
        buttons.emplace(name, button);
    }

    CButton& getButton(const std::string& name) { return buttons.at(name); }

    CButton* getButtonAt(int x, int y) {
        for (auto& [name, button] : buttons) {
            if (button.isButtonAt(x, y)) {
                return &button;
            }
        }
        return nullptr;
    }

    // --- Event handling ---
    void handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY);
    virtual void onClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {};

    // --- Rendering ---
    virtual void renderScreen(SDL_Renderer* renderer, int mouseX, int mouseY);
    virtual void renderButtons(SDL_Renderer* renderer, int mouseX, int mouseY);
    ChessGame* gameInstance;

private:
    // --- State ---
    std::unordered_map<std::string, CButton> buttons;
};

#endif // CCHESS_GAMESCREEN_H
