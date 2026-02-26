#pragma once

#include "Figure.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Headers.hpp"


// class Figure;
// class Pawn;

class Board
{
    public:
        std::vector<Figure *> whiteFigures;
        std::vector<Figure *> blackFigures;

        void initField();
       
        void initPawns(std::string color);
        void initKnight(std::string color);
        void initRook(std::string color);
        void initBishop(std::string color);
        void initKingAndQueen(std::string color);
        
        void initWhite();
        void initBlack();
};