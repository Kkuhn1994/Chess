#pragma once

#include "Headers.hpp"

class Pawn : public Figure
{
    public:
        Pawn(const int xPos, const int yPos, const std::string color);
        ~Pawn() override = default;

        void move(const std::array<int, 2> newField) override;
};