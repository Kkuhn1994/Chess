#include "../include/Pawn.hpp"



Pawn::Pawn(const int xPos, const int yPos)
{
    position[0] = xPos;
    position[1] = yPos;
}

void Pawn::move(const std::array<int, 2> newField)
{
    position = newField; 
}