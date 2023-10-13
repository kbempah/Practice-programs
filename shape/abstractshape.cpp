#include "abstractshape.h"

Shape::Shape(const std::string_view& n)
    :name{n}
{}

Shape::~Shape()
{}

std::string_view Shape::getName() const { return name; }