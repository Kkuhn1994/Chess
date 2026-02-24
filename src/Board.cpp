#include "../include/Board.hpp"

void Board::initPawns(std::string color)
{
    std::vector<Figure *> &figures = (color == "white") ? whiteFigures : blackFigures;
    int yPosition = (color == "white") ? 2 : 7;
    for(int xPosition = 1; xPosition <= 8; xPosition ++)
    {
        std::cout << xPosition << ":" << yPosition << "\n";
        Pawn *newPawn = new Pawn(xPosition, yPosition);

        figures.push_back(newPawn);
    }
}

void Board::initWhite()
{
    initPawns("white");
}

void Board::initBlack()
{
    initPawns("black");
}

void Board::initField()
{
    initWhite();
    initBlack();
}

