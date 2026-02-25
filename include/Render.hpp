#pragma once

#include "Headers.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int WINDOW_SIZE = 800;
const int TILE_SIZE = WINDOW_SIZE / 8;

class Board;

class Render
{
    public:
        void renderFigures();
        void displayField();
        void initGame();
        void loadTextures();
        void choseTexture(const Figure &toRender);
        Board *boardState;
         

    private:
        

        SDL_Renderer* renderer;
        SDL_Window* window;

        SDL_Texture* whitePawnTexture;
        SDL_Texture* whiteKnightTexture;
        SDL_Texture* whiteBishopTexture;
        SDL_Texture* whiteRookTexture;
        SDL_Texture* whiteKingTexture;
        SDL_Texture* whiteQueenTexture;

        SDL_Texture* blackPawnTexture;
        SDL_Texture* blackKnightTexture;
        SDL_Texture* blackBishopTexture;
        SDL_Texture* blackRookTexture;
        SDL_Texture* blackKingTexture;
        SDL_Texture* blackQueenTexture;
        SDL_Texture* myTexture;
};
