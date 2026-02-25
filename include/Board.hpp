#pragma once

#include "Headers.hpp"



class Figure;

class Board
{
    public:
        std::vector<Figure *> whiteFigures;
        std::vector<Figure *> blackFigures;

        void initField();
       
        void initPawns(std::string color);
        void initKnight(std::string color);
        
        void initWhite();
        void initBlack();
};