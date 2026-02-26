#include "../include/Queen.hpp"

Queen::Queen(const int xPos, const int yPos, const std::string colour) : Rook(colour), Bishop(colour), Figure(colour), type("Queen")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Queen::move(const std::array<int, 2> newField)
{
    position = newField; 
}

const std::string Queen::getType() const
{
    return Queen::type; 
}