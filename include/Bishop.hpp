#pragma once

#include "Headers.hpp"

class Bishop : public Figure
{
    public:
        Bishop(const int xPos, const int yPos, const std::string color);
        ~Bishop() override = default;

        void move(const std::array<int, 2> newField) override;
};