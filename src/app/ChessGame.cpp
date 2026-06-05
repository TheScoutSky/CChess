//
// Created by Antonio Wil on 30.05.26.
//

#include "app/ChessGame.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "chess/pieces/Pawn.h"

// --------------------------------------------------
// Construction
// --------------------------------------------------

ChessGame::ChessGame(ChessBoard* board, ChessTeam* blackTeam, ChessTeam* whiteTeam, ChessGameSettings* settings)
    : settings(settings), board(board), blackTeam(blackTeam), whiteTeam(whiteTeam) {
}

// --------------------------------------------------
// Event Handling
// --------------------------------------------------

void ChessGame::handleClick(SDL_MouseButtonEvent event, int mouseX, int mouseY) {
    (void)event;

    currentScreen->handleClick(event, mouseX, mouseY);
}

// --------------------------------------------------
// Helpers
// --------------------------------------------------

bool ChessGame::isMouseInside(SDL_Rect rect, int mouseX, int mouseY) {
    return mouseX >= rect.x && mouseX <= rect.x + rect.w && mouseY >= rect.y &&
           mouseY <= rect.y + rect.h;
}

SDL_Texture* ChessGame::loadTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        std::cerr << "IMG_Load failed: " << IMG_GetError() << '\n';
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << '\n';
        return nullptr;
    }

    return texture;
}

// --------------------------------------------------
// Rendering
// --------------------------------------------------

void ChessGame::renderBoard(SDL_Renderer* renderer, int xOffset, int yOffset, int fieldSize,
                            int mouseX, int mouseY) {

    for (auto chess_field : board->board) {
        SDL_Rect fieldRect = {xOffset + chess_field.x * fieldSize,
                              yOffset + chess_field.y * fieldSize, fieldSize, fieldSize};

        bool hovered = isMouseInside(fieldRect, mouseX, mouseY);

        chess_field.draw(renderer, xOffset + chess_field.x * fieldSize,
                         yOffset + chess_field.y * fieldSize, fieldSize, hovered, false);
    }
}

void ChessGame::renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y,
                           SDL_Color color) {
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

void ChessGame::renderButton(SDL_Renderer* renderer, TTF_Font* font, SDL_Rect rect,
                             const char* text, bool hovered) {
    if (hovered) {
        SDL_SetRenderDrawColor(renderer, 90, 90, 130, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 55, 55, 85, 255);
    }

    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 190, 190, 230, 255);
    SDL_RenderDrawRect(renderer, &rect);

    int textWidth = 0;
    int textHeight = 0;

    TTF_SizeUTF8(font, text, &textWidth, &textHeight);

    int textX = rect.x + rect.w / 2 - textWidth / 2;
    int textY = rect.y + rect.h / 2 - textHeight / 2;

    SDL_Color textColor = {255, 255, 255, 255};

    renderText(renderer, font, text, textX, textY, textColor);
}

void ChessGame::renderTitleScreen(SDL_Renderer* renderer, TTF_Font* titleFont, TTF_Font* buttonFont,
                                  int width, int height, SDL_Rect startButton,
                                  SDL_Rect optionsButton, SDL_Rect quitButton, float scaleX,
                                  float scaleY) {
    int logicalMouseX = 0;
    int logicalMouseY = 0;

    SDL_GetMouseState(&logicalMouseX, &logicalMouseY);

    // Scale mouse coordinates to match renderer output size
    mouseX = (int)(logicalMouseX * scaleX);
    mouseY = (int)(logicalMouseY * scaleY);

    SDL_Color titleColor = {240, 240, 255, 255};

    const char* title = "CHESS";

    int titleWidth = 0;
    int titleHeight = 0;

    TTF_SizeUTF8(titleFont, title, &titleWidth, &titleHeight);

    renderText(renderer, titleFont, title, width / 2 - titleWidth / 2, height / 5, titleColor);

    renderButton(renderer, buttonFont, startButton, "Start",
                 isMouseInside(startButton, mouseX, mouseY));

    renderButton(renderer, buttonFont, optionsButton, "Options",
                 isMouseInside(optionsButton, mouseX, mouseY));

    renderButton(renderer, buttonFont, quitButton, "Quit",
                 isMouseInside(quitButton, mouseX, mouseY));
}

// --------------------------------------------------
// Main Loop
// --------------------------------------------------

int ChessGame::openGame() {
    // --- SDL setup ---
    SDL_SetMainReady();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
        return 1;
    }

    if (TTF_Init() != 0) {
        std::cerr << "TTF_Init failed: " << TTF_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    // --- Window and renderer setup ---
    SDL_Window* window =
        SDL_CreateWindow("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings->screenWidth, settings->screenHeight,
                         SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }

    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // --- Font loading ---
    TTF_Font* titleFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 96);
    TTF_Font* buttonFont =
        TTF_OpenFont("/Users/antoniowil/Documents/New project/CChess/assets/fonts/arial.ttf", 36);

    if (titleFont == nullptr || buttonFont == nullptr) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << '\n';

        if (titleFont != nullptr) {
            TTF_CloseFont(titleFont);
        }

        if (buttonFont != nullptr) {
            TTF_CloseFont(buttonFont);
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // --- Asset loading ---
    SDL_Texture* whitePawnTexture = loadTexture(
        renderer, "/Users/antoniowil/Documents/New project/CChess/assets/pieces/white_pawn.png");
    Pawn whitePawn = Pawn(whiteTeam, board->getField(2, 3), whitePawnTexture);
    board->getField(2, 3)->setPiece(&whitePawn);

    currentScreen->registerTextures();

    isGameRunning = true;

    // --- Game loop ---
    while (isGameRunning) {
        int windowWidth = 0;
        int windowHeight = 0;
        SDL_GetWindowSize(window, &windowWidth, &windowHeight);

        int rendererWidth = 0;
        int rendererHeight = 0;
        SDL_GetRendererOutputSize(renderer, &rendererWidth, &rendererHeight);

        // Calculate scale factor for mouse coordinates
        float scaleX = (float)rendererWidth / windowWidth;
        float scaleY = (float)rendererHeight / windowHeight;

        int width = rendererWidth;
        int height = rendererHeight;

        SDL_Event event;

        // --- Event processing ---
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                isGameRunning = false;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
            }

            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = (int)(event.button.x * scaleX);
                    int mouseY = (int)(event.button.y * scaleY);

                    handleClick(event.button, mouseX, mouseY);
                }
            }
        }

        // --- Frame rendering ---
        SDL_SetRenderDrawColor(renderer, 18, 22, 33, 255);
        SDL_RenderClear(renderer);

        int logicalMouseX = 0, logicalMouseY = 0;
        SDL_GetMouseState(&logicalMouseX, &logicalMouseY);

        mouseX = static_cast<int>(logicalMouseX * scaleX);
        mouseY = static_cast<int>(logicalMouseY * scaleY);

        currentScreen->renderScreen(renderer);
        currentScreen->renderButtons(renderer, mouseX, mouseY);

        SDL_RenderPresent(renderer);
    }

    // --- Cleanup ---
    TTF_CloseFont(titleFont);
    TTF_CloseFont(buttonFont);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
