#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int WINDOW_SIZE = 800;
const int TILE_SIZE = WINDOW_SIZE / 8;

class Figure;

Figure *findFigure(std::array<int, 2> newField);

