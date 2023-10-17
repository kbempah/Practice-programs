#include "abstractshape.h"

Shape::Shape(const std::string_view& n)
    :name{n}
{}

Shape::~Shape()
{}

auto Shape::getName() -> std::string_view const { return name; }