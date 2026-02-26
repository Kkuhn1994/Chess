#pragma once

#include "Figure.hpp"
#include "Headers.hpp"

class Bishop : virtual public Figure
{
    public:
        Bishop(const int xPos, const int yPos, const std::string color);
        Bishop(const std::string color) : Figure(color) {};
        ~Bishop() override = default;

        void move(const std::array<int, 2> newField) override;
        const std::string getType() const override;
};