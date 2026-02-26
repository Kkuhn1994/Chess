#include "../include/Pawn.hpp"

Pawn::Pawn(const int xPos, const int yPos, const std::string colour) : Figure(colour, "Pawn")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Pawn::move(const std::array<int, 2> newField)
{
    position = newField; 
}

const std::string Pawn::getType() const
{
    return Figure::type; 
}