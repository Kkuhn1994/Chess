#pragma once

#include "Headers.hpp"


class Figure
{
    public:
        // Figure() {};
        Figure(const std::string colour) : color(colour) {};
        Figure(const std::string colour, const std::string type) : type(type), color(colour){};
        virtual ~Figure() = 0;
        virtual void move(const std::array<int, 2> newField) = 0;
        virtual const std::string getType() const = 0;

        std::array<int, 2> position;
        const std::string type;
        const std::string color;
};

inline Figure::~Figure() {}