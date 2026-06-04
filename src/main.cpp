#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_net.h>
#include <SDL_ttf.h>

#include <algorithm>
#include <cmath>
#include <iostream>

#include "ChessGame.h"
#include "ChessPieces/Pawn.h"

int main() {

    auto* blackTeam = new ChessTeam(ChessTeamColor::BLACK);
    auto* whiteTeam = new ChessTeam(ChessTeamColor::WHITE);
    auto* board = new ChessBoard(8, 8);

    auto* game = new ChessGame(board, whiteTeam, blackTeam);

    game->openGame();
    return 0;
}
