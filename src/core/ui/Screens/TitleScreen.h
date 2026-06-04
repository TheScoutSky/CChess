//
// Created by Antonio Wil on 04.06.26.
//

#ifndef CCHESS_TITLESCREEN_H
#define CCHESS_TITLESCREEN_H
#include "../GameScreen.h"


class TitleScreen : public GameScreen {

    public:
    void renderScreen(SDL_Renderer* renderer) override;
    void registerTextures() override;

    TitleScreen();
};


#endif //CCHESS_TITLESCREEN_H
