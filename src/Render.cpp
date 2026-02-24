#include "../include/Render.hpp"

SDL_Texture* Render::loadTexture(const char *file, SDL_Renderer* renderer) {
    SDL_Surface* surface = SDL_LoadBMP(file);
    if (!surface) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void Render::displayField()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(
        "8x8 Board", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_SIZE, WINDOW_SIZE, SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    // Hintergrund schwarz
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0)
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // weiß
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);       // schwarz

            SDL_Rect rect = { col * TILE_SIZE, row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderFillRect(renderer, &rect);
        }
    }
    SDL_RenderPresent(renderer);
}


void Render::renderFigures()
{

std::cout << "render Figures\n";

    SDL_Surface* tempSurface = SDL_LoadBMP("./pictures/white-pawn.bmp");
    if (!tempSurface) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

    }

    SDL_Texture* myTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (!myTexture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);

    }



    for(size_t figureNr = 0; figureNr < boardState->whiteFigures.size(); figureNr++)
    {
        // std::cout << boardState->whiteFigures[figureNr]->position[0] << ":" << boardState->whiteFigures[figureNr]->position[1] << "\n";
        int xPos = (boardState->whiteFigures[figureNr]->position[0] - 1) * TILE_SIZE + TILE_SIZE / 5;
        int yPos = (8 - boardState->whiteFigures[figureNr]->position[1]) * TILE_SIZE + TILE_SIZE / 7;

        SDL_Rect destRect;
        destRect.x = xPos;  // Position von links
        destRect.y = yPos;  // Position von oben
        destRect.w = 60;   // Breite der Textur
        destRect.h = 75;   // Höhe der Textur
        // Textur rendern
        SDL_RenderCopy(renderer, myTexture, NULL, &destRect);     
    }


    // Renderer präsentieren
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    SDL_DestroyTexture(myTexture);
}


void Render::initGame()
{
    boardState = new Board();
}