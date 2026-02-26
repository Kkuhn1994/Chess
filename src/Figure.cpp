#include "../include/Headers.hpp"
#include "../include/Figure.hpp"

bool Figure::passFields(std::array<int, 2> oldField, std::array<int, 2> newField)
{
    // std::cout << "passFields\n";
    int deltaX = newField[0] - oldField[0];
    int deltaY  = newField[1] - oldField[1];
    int directionX = (deltaX == 0) ? 0 : (deltaX / abs(deltaX));
    int directionY = (deltaY == 0) ? 0 : (deltaY / abs(deltaY));
    
    for(int i = 1;i < std::max(abs(deltaX), abs(deltaY)); i ++)
    {
        std::array<int, 2> passedField;
        passedField[0] = oldField[0] + i * directionX;
        passedField[1] = oldField[1] + i * directionY;
        if(findFigure(passedField))
        {
            std::cout << "passFiels figure Passed\n";
            return false;
        }
    }
    return true;
}