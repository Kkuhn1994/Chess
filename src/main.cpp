#include "../include/Headers.hpp"
#include "../include/Figure.hpp"
#include "../include/Render.hpp"
#include "../include/Board.hpp"


SDL_Event event;
bool running = true;
Render renderBoard;

Figure *findFigure(std::array<int, 2> newField)
{
    for(int i = 0 ; i < renderBoard.boardState->whiteFigures.size(); i ++)
    {
        std::array<int, 2> position = renderBoard.boardState->whiteFigures[i]->position;
        if(position[0] == newField[0] && position[1] == newField[1])
        {
            std::cout << "find  Figure\n";
            return renderBoard.boardState->whiteFigures[i];
        }
    }
    for(int i = 0 ; i < renderBoard.boardState->blackFigures.size(); i ++)
    {
        std::array<int, 2> position = renderBoard.boardState->blackFigures[i]->position;
        if(position[0] == newField[0] && position[1] == newField[1])
        {
            std::cout << "find  Figure\n";
            return renderBoard.boardState->blackFigures[i];
        }
    }
    
    return NULL;
}

std::array<int, 2> clickCordinate()
{
    std::array<int, 2> newField;
    int x = event.button.x;
    int y = event.button.y;    
    int xCordinate = x / TILE_SIZE + 1;
    int yCordinate = 8 - y / TILE_SIZE;
    newField[0] = xCordinate;
    newField[1] = yCordinate;
    return newField;
}

void figureChosenLoop(Figure *clickedFigure)
{
   while (running)
    {
        // renderBoard.renderFigures();
        // 1️⃣ Events verarbeiten
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                
                Figure *hitFigure = findFigure(clickCordinate());
                if(hitFigure)
                {
                    if(hitFigure->color.compare(clickedFigure->color))
                    {
                        clickedFigure->move(clickCordinate());
                        // std::cout << "remove\n";
                        auto& white = renderBoard.boardState->whiteFigures;
                        auto& black = renderBoard.boardState->blackFigures;

                        // Entferne Pointer aus den Vektoren
                        white.erase(std::remove(white.begin(), white.end(), hitFigure), white.end()); 
                        black.erase(std::remove(black.begin(), black.end(), hitFigure), black.end());
                        delete hitFigure;                 
                    }
                    return;
                }
                clickedFigure->move(clickCordinate());
                return;
                
            }
        }
        SDL_Delay(500);
    }
}

int main(void)
{
    

    renderBoard.initGame();
    renderBoard.initWindow();
    renderBoard.displayField();
    renderBoard.boardState->initField();
    renderBoard.loadTextures();
    while (running)
    {
        SDL_RenderClear(renderBoard.renderer);
        renderBoard.displayField();
        renderBoard.renderFigures();
        SDL_RenderPresent(renderBoard.renderer);
        
        // 1️⃣ Events verarbeiten
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                Figure *clickedFigure = findFigure(clickCordinate());
                if(clickedFigure)
                {
                    figureChosenLoop(clickedFigure);
                }
            }
        }
        SDL_Delay(500);
    }
}