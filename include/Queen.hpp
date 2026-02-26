#pragma once

#include "Rook.hpp"
#include "Bishop.hpp"


class Queen : public Rook, public Bishop
{
    public:
        Queen(const int xPos, const int yPos, const std::string color);
        ~Queen() override = default;

        void move(const std::array<int, 2> newField) override;
        const std::string getType() const override;

        const std::string type;
};