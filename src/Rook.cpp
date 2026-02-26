#include "../include/Rook.hpp"
#include "../include/Figure.hpp"

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
    if(newField[0] == position[0] || newField[1] == position[1])
    {
        if(passFields(position, newField))
        {
            position = newField;
        }
    }
}

const std::string Rook::getType() const
{
    return Figure::type; 
}