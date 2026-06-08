//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSGAME_H
#define CCHESS_CHESSGAME_H
#include "SDL_ttf.h"
#include <SDL.h>

#include "chess/board/ChessBoard.h"
#include "chess/model/ChessGameSettings.h"
#include "chess/model/ChessTeam.h"
#include "chess/moves/ChessMove.h"
#include "ui/screens/PlayingScreen.h"
#include "ui/screens/TitleScreen.h"

enum class ChessScreen { Title, Playing, Options };

class ChessGame {

public:
    // --- Lifecycle ---
    ChessGame(ChessBoard* board, ChessTeam* blackTeam, ChessTeam* whiteTeam, ChessGameSettings* settings);

    int openGame();

    void switchScreen(GameScreen* gameScreen) {
        gameScreen->preload();
        currentScreen = gameScreen;
    };

    int getMouseX() {
        return mouseX;
    };

    int getMouseY() {
        return mouseY;
    }

    ChessGameSettings* getSettings() {
        return settings;
    }

    ChessBoard* getBoard() {
        return board;
    }

    void quitGame() {
        isGameRunning = false;
    };

    TitleScreen* titleScreen = new TitleScreen(this);
    PlayingScreen* playingScreen = new PlayingScreen(this);
    ChessField* selectedField = nullptr;

private:
    // --- Resource loading ---
    static SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);

    // --- Rendering ---
    void renderBlackTeam();
    void renderWhiteTeam();

    void renderGameOver();

    bool startGame();
    bool endGame();
    bool pauseGame();

    // --- Event handling ---
    void handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY);

    // --- Helpers ---
    bool isMouseInside(SDL_Rect rect, int mouseX, int mouseY);

    // --- Screen state ---
    bool isGameRunning = false;


    GameScreen* currentScreen = titleScreen;


    static void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y,
                           SDL_Color color);

    void renderButton(SDL_Renderer* renderer, TTF_Font* font, SDL_Rect rect, const char* text,
                      bool hovered);

    void renderTitleScreen(SDL_Renderer* renderer, TTF_Font* titleFont, TTF_Font* buttonFont,
                           int width, int height, SDL_Rect startButton, SDL_Rect optionsButton,
                           SDL_Rect quitButton, float scaleX, float scaleY);

    // --- Game state ---
    ChessGameSettings* settings;
    ChessBoard* board;
    ChessTeam* blackTeam;
    ChessTeam* whiteTeam;

    // --- Mouse State ---
    int mouseX, mouseY;


    ChessMove* moves[];
};

#endif // CCHESS_CHESSGAME_H
