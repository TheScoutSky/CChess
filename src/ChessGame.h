//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSGAME_H
#define CCHESS_CHESSGAME_H
#include <SDL.h>
#include "SDL_ttf.h"

#include "core/ChessBoard.h"
#include "core/logic/ChessMove.h"
#include "core/ChessTeam.h"
#include "core/data/ChessGameSettings.h"
#include "core/ui/Screens/TitleScreen.h"

enum class ChessScreen {
    Title,
    Playing,
    Options
};



class ChessGame {

    public:

    ChessGame(ChessBoard* board, ChessTeam* blackTeam, ChessTeam* whiteTeam);

    int openGame();


    private:

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);

    void renderBoard(SDL_Renderer* renderer, int xOffset, int yOffset, int fieldSize, int mouseX, int mouseY);
    void renderBlackTeam();
    void renderWhiteTeam();

    void renderGameOver();

    bool startGame();
    bool endGame();
    bool pauseGame();

    // Events
    void handleClick(
        SDL_MouseButtonEvent event,
        int mouseX,
        int mouseY
    );

    bool isGameRunning = false;

    TitleScreen* titleScreen = new TitleScreen();

    GameScreen* currentScreen = titleScreen;

    void renderText(
        SDL_Renderer* renderer,
        TTF_Font* font,
        const char* text,
        int x,
        int y,
        SDL_Color color
    );

    void renderButton(
        SDL_Renderer* renderer,
        TTF_Font* font,
        SDL_Rect rect,
        const char* text,
        bool hovered
    );

    void renderTitleScreen(
        SDL_Renderer* renderer,
        TTF_Font* titleFont,
        TTF_Font* buttonFont,
        int width,
        int height,
        SDL_Rect startButton,
        SDL_Rect optionsButton,
        SDL_Rect quitButton,
        float scaleX,
        float scaleY
    );

    bool isMouseInside(SDL_Rect rect, int mouseX, int mouseY);

    ChessGameSettings gameSettings;
    ChessBoard *board;
    ChessTeam *blackTeam;
    ChessTeam *whiteTeam;
    ChessMove *moves[];




};


#endif //CCHESS_CHESSGAME_H
