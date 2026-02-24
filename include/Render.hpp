#pragma once

#include "Headers.hpp"

#include <SDL2/SDL.h>

const int WINDOW_SIZE = 800;
const int TILE_SIZE = WINDOW_SIZE / 8;

class Board;

class Render
{
    public:
        void renderFigures();
        void displayField();
        void initGame();
        SDL_Texture* loadTexture(const char *file, SDL_Renderer* renderer);
        Board *boardState;
         

    private:
        

        SDL_Renderer* renderer;
        SDL_Window* window;
        SDL_Texture* myTexture;
};
