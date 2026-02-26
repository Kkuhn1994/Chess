#pragma once

#include "Figure.hpp"
#include "Headers.hpp"

void passField();

class Rook : virtual public Figure
{
    public:
        Rook(const std::string color) : Figure(color){};
        Rook(const int xPos, const int yPos, const std::string color);
        ~Rook() override = default;

        const std::string getType() const override;
        void move(const std::array<int, 2> newField) override;
};