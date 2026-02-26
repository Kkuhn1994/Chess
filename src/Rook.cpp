#include "../include/Rook.hpp"

// Rook::Rook(const std::string colour) : Figure(colour)
// {
 
// }

Rook::Rook(const int xPos, const int yPos, const std::string colour) : Figure(colour, "Rook")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Rook::move(const std::array<int, 2> newField)
{
    position = newField; 
}

const std::string Rook::getType() const
{
    return Figure::type; 
}