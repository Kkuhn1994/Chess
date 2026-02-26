#include "../include/Render.hpp"

void Render::initWindow()
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
}


void Render::displayField()
{
    // Hintergrund schwarz
    std::cout << "displayField\n";
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // SDL_RenderClear(renderer);

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
    
}


void Render::choseTexture(const Figure &toRender)
{
    // std::cout << toRender.color << "::" << toRender.type << "\n";
    if(!toRender.color.compare("white") && !toRender.type.compare("Pawn"))
    {
        myTexture = whitePawnTexture;
    }
    if(!toRender.color.compare("white") && !toRender.type.compare("Knight"))
    {
        myTexture = whiteKnightTexture;
    }
    if(!toRender.color.compare("white") && !toRender.type.compare("Bishop"))
    {
        myTexture = whiteBishopTexture;
    }
    if(!toRender.color.compare("white") && !toRender.type.compare("Rook"))
    {
        myTexture = whiteRookTexture;
    }
    if(!toRender.color.compare("white") && !toRender.type.compare("King"))
    {
        myTexture = whiteKingTexture;
    }
    if(!toRender.color.compare("white") && !toRender.type.compare("Queen"))
    {
        myTexture = whiteQueenTexture;
    }


    if(!toRender.color.compare("black") && !toRender.type.compare("Pawn"))
    {
        myTexture = blackPawnTexture;
    }
    if(!toRender.color.compare("black") && !toRender.type.compare("Knight"))
    {
        myTexture = blackKnightTexture;
    }
    if(!toRender.color.compare("black") && !toRender.type.compare("Bishop"))
    {
        myTexture = blackBishopTexture;
    }
    if(!toRender.color.compare("black") && !toRender.type.compare("Rook"))
    {
        myTexture = blackRookTexture;
    }
    if(!toRender.color.compare("black") && !toRender.type.compare("King"))
    {
        myTexture = blackKingTexture;
    }
    if(!toRender.color.compare("black") && !toRender.type.compare("Queen"))
    {
        myTexture = blackQueenTexture;
    }
}

void Render::loadTextures()
{
    whitePawnTexture = IMG_LoadTexture(renderer, "./pictures/white-pawn.png");
    if (!whitePawnTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    whiteKnightTexture = IMG_LoadTexture(renderer, "./pictures/white-knight.png");
    if (!whiteKnightTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    whiteBishopTexture = IMG_LoadTexture(renderer, "./pictures/white-bishop.png");
    if (!whiteBishopTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    whiteRookTexture = IMG_LoadTexture(renderer, "./pictures/white-rook.png");
    if (!whiteRookTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    whiteKingTexture = IMG_LoadTexture(renderer, "./pictures/white-king.png");
    if (!whiteKingTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    whiteQueenTexture = IMG_LoadTexture(renderer, "./pictures/white-queen.png");
    if (!whiteQueenTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }

    blackPawnTexture = IMG_LoadTexture(renderer, "./pictures/black-pawn.png");
    if (!blackPawnTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    blackKnightTexture = IMG_LoadTexture(renderer, "./pictures/black-knight.png");
    if (!blackKnightTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    blackBishopTexture = IMG_LoadTexture(renderer, "./pictures/black-bishop.png");
    if (!blackBishopTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    blackRookTexture = IMG_LoadTexture(renderer, "./pictures/black-rook.png");
    if (!blackRookTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    blackKingTexture = IMG_LoadTexture(renderer, "./pictures/black-king.png");
    if (!blackKingTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
    blackQueenTexture = IMG_LoadTexture(renderer, "./pictures/black-queen.png");
    if (!blackQueenTexture) {
        std::cout << "IMG_LoadTexture Error: " << IMG_GetError() << std::endl;
    }
}


void Render::renderFigures()
{

    std::cout << "render Figures\n";
    for(size_t figureNr = 0; figureNr < boardState->whiteFigures.size(); figureNr++)
    {
        std::cout << boardState->whiteFigures.size() << " size\n";
        std::cout << figureNr << " figureNr\n";
        // std::cout << boardState->whiteFigures[figureNr]->position[0] << ":" << boardState->whiteFigures[figureNr]->position[1] << "\n";
        int xPos = (boardState->whiteFigures[figureNr]->position[0] - 1) * TILE_SIZE + TILE_SIZE / 5;
        int yPos = (8 - boardState->whiteFigures[figureNr]->position[1]) * TILE_SIZE + TILE_SIZE / 7;
        std::cout << "test\n";
        SDL_Rect destRect;
        destRect.x = xPos;  // Position von links
        destRect.y = yPos;  // Position von oben
        destRect.w = 60;   // Breite der Textur
        destRect.h = 75;   // Höhe der Textur
        // Textur rendern 
        choseTexture(*boardState->whiteFigures[figureNr]);
        std::cout << "test\n";
        SDL_RenderCopy(renderer, myTexture, NULL, &destRect);   
    }


    for(size_t figureNr = 0; figureNr < boardState->blackFigures.size(); figureNr++)
    {
        std::cout << boardState->blackFigures.size() << " size\n";
        std::cout << figureNr << " figureNr\n";
        // std::cout << boardState->blackFigures[figureNr]->position[0] << ":" << boardState->blackFigures[figureNr]->position[1] << "\n";
        int xPos = (boardState->blackFigures[figureNr]->position[0] - 1) * TILE_SIZE + TILE_SIZE / 5;
        int yPos = (8 - boardState->blackFigures[figureNr]->position[1]) * TILE_SIZE + TILE_SIZE / 7;

        SDL_Rect destRect;
        destRect.x = xPos;  // Position von links
        destRect.y = yPos;  // Position von oben
        destRect.w = 60;   // Breite der Textur
        destRect.h = 75;   // Höhe der Textur
        // Textur rendern 
        choseTexture(*boardState->blackFigures[figureNr]);
        SDL_RenderCopy(renderer, myTexture, NULL, &destRect);   
    }
    



    
    // Renderer präsentieren
    
    
}


void Render::initGame()
{
    boardState = new Board();
}