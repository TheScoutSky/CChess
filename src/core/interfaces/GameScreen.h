//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_GAMESCREEN_H
#define CCHESS_GAMESCREEN_H
#include <SDL_events.h>
#include <unordered_map>
#include <string>

#include "../ui/CButton.h"


class GameScreen {

    public:

    virtual ~GameScreen() = default;

    CButton &getButton(const std::string &name) {
        return buttons.at(name);
    }

    // --- Event Handling --- //
    void handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY);

    // --- Rendering --- //
    void renderScreen();
    void renderButtons();

    private:
    std::unordered_map<std::string, CButton> buttons;
};


#endif //CCHESS_GAMESCREEN_H
