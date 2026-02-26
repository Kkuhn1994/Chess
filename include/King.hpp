#pragma once

#include "Rook.hpp"
#include "Bishop.hpp"


class King : public Rook, public Bishop
{
    public:
        King(const int xPos, const int yPos, const std::string color);
        ~King() override = default;

        void move(const std::array<int, 2> newField) override;
        const std::string getType() const override;

        const std::string type;
};