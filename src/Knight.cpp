#include "../include/Knight.hpp"

Knight::Knight(const int xPos, const int yPos, const std::string colour) : Figure(colour, "Knight")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Knight::move(const std::array<int, 2> newField)
{
    int deltaX = abs(newField[0] - position[0]);
    int deltaY = abs(newField[1] - position[1]);

    if(1 == std::min(deltaX, deltaY) && 2 == std::max(deltaX, deltaY))
    {
        position = newField; 
    } 
}

const std::string Knight::getType() const
{
    return Figure::type; 
}