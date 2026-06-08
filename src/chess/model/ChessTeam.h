//
// Created by Antonio Wil on 30.05.26.
//

#ifndef CCHESS_CHESSTEAM_H
#define CCHESS_CHESSTEAM_H

enum ChessTeamColor {
    WHITE,
    BLACK,
};

class ChessTeam {
public:
    // --- Construction ---
    ChessTeam(ChessTeamColor color) : color(color) {};
    ChessTeamColor color;

private:
    // --- State ---
};

#endif // CCHESS_CHESSTEAM_H
