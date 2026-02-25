#include "../include/Headers.hpp"

int main(void)
{
    Render renderBoard;

    renderBoard.initGame();
    renderBoard.displayField();
    renderBoard.boardState->initField();
    renderBoard.loadTextures();
    while(1)
    {
        renderBoard.renderFigures();
        SDL_Delay(100);
    }
}