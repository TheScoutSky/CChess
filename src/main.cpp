#define SDL_MAIN_HANDLED

#include "app/ChessGame.h"
#include "chess/pieces/Pawn.h"

int main() {

    auto* settings = new ChessGameSettings();
    auto* blackTeam = new ChessTeam(ChessTeamColor::BLACK);
    auto* whiteTeam = new ChessTeam(ChessTeamColor::WHITE);
    auto* board = new ChessBoard(settings);

    auto* game = new ChessGame(board, whiteTeam, blackTeam, settings);

    game->openGame();
    return 0;
}
