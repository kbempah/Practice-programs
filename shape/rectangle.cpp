#include <iostream>
#include "rectangle.h"

Rectangle::Rectangle(const std::string_view& n, double w, double l)
    :Shape{n}, width{w}, length{l}
{}

auto Rectangle::getWidth(void) -> double const
{
    return width;
}

auto Rectangle::getLength(void) -> double const
{
    return length;
}

auto Rectangle::setWidth(double w) -> void
{
    if (w < 0) {
        std::cout << "Could not update width property.\n";
    } else {
        width = w;
    }
}

auto Rectangle::setLength(double l) -> void
{
    if (l < 0) {
        std::cout << "Could not update length property.\n";
    } else {
        length = l;
    }
}

auto Rectangle::getArea(void) -> double const
{
    return width * length;
}