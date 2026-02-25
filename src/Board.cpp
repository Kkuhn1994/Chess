#include "../include/Board.hpp"

void Board::initKnight(std::string color)
{
    std::vector<Figure *> &figures = (color == "white") ? whiteFigures : blackFigures;
    int yPosition = (color == "white") ? 1 : 8;
    Knight *newKnight = new Knight(2, yPosition, color);
    figures.push_back(newKnight);
    Knight *newKnight2 = new Knight(7, yPosition, color);
    figures.push_back(newKnight2);
}


void Board::initRook(std::string color)
{
    std::vector<Figure *> &figures = (color == "white") ? whiteFigures : blackFigures;
    int yPosition = (color == "white") ? 1 : 8;
    Rook *newRook = new Rook(1, yPosition, color);
    figures.push_back(newRook);
    Rook *newRook2 = new Rook(8, yPosition, color);
    figures.push_back(newRook2);
}

void Board::initBishop(std::string color)
{
    std::vector<Figure *> &figures = (color == "white") ? whiteFigures : blackFigures;
    int yPosition = (color == "white") ? 1 : 8;
    Bishop *newBishop = new Bishop(3, yPosition, color);
    figures.push_back(newBishop);
    Bishop *newBishop2 = new Bishop(6, yPosition, color);
    figures.push_back(newBishop2);
}
void Board::initPawns(std::string color)
{
    std::vector<Figure *> &figures = (color == "white") ? whiteFigures : blackFigures;
    int yPosition = (color == "white") ? 2 : 7;
    for(int xPosition = 1; xPosition <= 8; xPosition ++)
    {
        std::cout << xPosition << ":" << yPosition << "\n";
        Pawn *newPawn = new Pawn(xPosition, yPosition, color);
        figures.push_back(newPawn);
    }
}

void Board::initWhite()
{
    initPawns("white");
    initKnight("white");
    initBishop("white");
    initRook("white");
}

void Board::initBlack()
{
    initPawns("black");
    initKnight("black");
    initBishop("black");
    initRook("black");
}

void Board::initField()
{
    initWhite();
    initBlack();
}

