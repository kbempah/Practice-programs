#include "circle.h"

Circle::Circle(const std::string_view& n, double r) : Shape{n}
{
    setRadius(r);
}

Circle::~Circle() {}

double Circle::getArea() const
{
    return Circle::PI * getRadius() * getRadius();
}