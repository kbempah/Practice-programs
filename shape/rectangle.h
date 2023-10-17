#include "abstractshape.h"

class Rectangle : public Shape
{
public:
    Rectangle(const std::string_view&, double, double);
    virtual ~Rectangle();
private:
    double width, length;
public:
    auto getWidth(void) -> double const;
    auto getLength(void) -> double const;
    void setWidth(double);
    void setLength(double);
    virtual auto getArea(void) -> double const override final;
};