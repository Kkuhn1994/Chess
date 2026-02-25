#pragma once

#include "Headers.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



class Board;

class Render
{
    public:
        void renderFigures();
        void initWindow();
        void displayField();
        void initGame();
        void loadTextures();
        void choseTexture(const Figure &toRender);
        Board *boardState;
        SDL_Renderer* renderer;
         

    private:
        

        
        SDL_Renderer* renderer2;
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
