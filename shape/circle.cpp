#include <iostream>
#include "circle.h"

Circle::Circle(const std::string_view& n, double r) : Shape{n}
{
    setRadius(r);
}

Circle::~Circle() {}

inline auto Circle::getArea() const -> double
{
    return Circle::PI * getRadius() * getRadius();
}

inline auto Circle::getRadius() const -> double
{
    return radius;
}

auto Circle::setRadius(double r) -> void
{
    if (r < 0) {
        std::cout << "Could not set radius...\n";
    } else {
        radius = r;
    }
}
