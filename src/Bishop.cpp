#include "../include/Bishop.hpp"

Bishop::Bishop(const int xPos, const int yPos, const std::string colour) : Figure(colour, "Bishop")
{
    position[0] = xPos;
    position[1] = yPos;
}

void Bishop::move(const std::array<int, 2> newField)
{
    position = newField; 
}

const std::string Bishop::getType() const
{
    return Figure::type; 
}