//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_GAMESCREEN_H
#define CCHESS_GAMESCREEN_H
#include <SDL_events.h>
#include <unordered_map>
#include <string>

#include "CButton.h"


class GameScreen {

    public:

    virtual ~GameScreen() = default;

    virtual void registerTextures();

    void addButton(const std::string &name, const CButton &button) {
        buttons.insert(std::pair<std::string, CButton>(name, button));
    }

    CButton &getButton(const std::string &name) {
        return buttons.at(name);
    }

    CButton* getButtonAt(int x, int y) {
        for (auto& [name, button] : buttons) {
            if (button.isButtonAt(x, y)) {
                return &button;
            }
        }
        return nullptr;
    }

    // --- Event Handling --- //
    void handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY);

    // --- Rendering --- //
    virtual void renderScreen(SDL_Renderer* renderer);
    virtual void renderButtons(SDL_Renderer* renderer,int mouseX, int mouseY);

    private:
    std::unordered_map<std::string, CButton> buttons;
};


#endif //CCHESS_GAMESCREEN_H
