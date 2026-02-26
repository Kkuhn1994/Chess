#pragma once

#include "Figure.hpp"
#include "Headers.hpp"

class Knight : public Figure
{
    public:
        Knight(const int xPos, const int yPos, const std::string color);
        ~Knight() override = default;

        const std::string getType() const override;
        void move(const std::array<int, 2> newField) override;
};