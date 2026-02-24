#include "../include/Headers.hpp"

int main(void)
{
    Render renderBoard;

    renderBoard.initGame();
    renderBoard.displayField();
    renderBoard.boardState->initField();
    while(1)
    {
        renderBoard.renderFigures();
    }
}