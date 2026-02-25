#include "../include/Knight.hpp"

Knight::Knight(const int xPos, const int yPos, const std::string colour) : Figure(colour, "Knight")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Knight::move(const std::array<int, 2> newField)
{
    position = newField; 
}