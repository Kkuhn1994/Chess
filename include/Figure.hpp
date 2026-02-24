#include "Headers.hpp"


class Figure
{
    public:
        virtual ~Figure() = 0;
        virtual void move(const std::array<int, 2> newField) = 0;

        std::array<int, 2> position;
};

inline Figure::~Figure() {}