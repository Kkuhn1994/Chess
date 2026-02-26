#include "../include/King.hpp"

King::King(const int xPos, const int yPos, const std::string colour) : Rook(colour), Bishop(colour), Figure(colour), type("King")
{
    position[0] = xPos;
    position[1] = yPos;
}

void King::move(const std::array<int, 2> newField)
{
    position = newField; 
}

const std::string King::getType() const
{
    return King::type; 
}