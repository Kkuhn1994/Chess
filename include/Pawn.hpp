#pragma once

#include "Headers.hpp"

class Pawn : public Figure
{
    public:
        Pawn(const int xPos, const int yPos);
        ~Pawn() override = default;

        void move(const std::array<int, 2> newField) override;
};