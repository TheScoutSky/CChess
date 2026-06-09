//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSTEAM_H
#define CCHESS_CHESSTEAM_H
#include <vector>

class ChessPiece;

enum ChessTeamColor {
    WHITE,
    BLACK,
};

class ChessTeam {
public:
    // --- Construction ---
    ChessTeam(ChessTeamColor color) : color(color) {};
    ChessTeamColor color;

    void takePiece(ChessPiece* piece) {;
        takenPieces.push_back(piece);
    }

    std::vector<ChessPiece*> getTakenPieces() { return takenPieces; }


private:
    // --- State ---

    std::vector<ChessPiece*> takenPieces;
};

#endif // CCHESS_CHESSTEAM_H
