#include "abstractshape.h"

class Rectangle : public Shape
{
public:
    Rectangle(const std::string_view&, double, double);
    virtual ~Rectangle() = default;
private:
    double width, length;
public:
    auto getWidth(void) -> double const;
    auto getLength(void) -> double const;
    auto setWidth(double) -> void;
    auto setLength(double) -> void;
    virtual auto getArea(void) -> double const override final;
};