#pragma once

#include "Headers.hpp"

class Rook : public Figure
{
    public:
        Rook(const int xPos, const int yPos, const std::string color);
        ~Rook() override = default;

        void move(const std::array<int, 2> newField) override;
};