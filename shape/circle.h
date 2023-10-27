#include "abstractshape.h"

class Circle : Shape
{
    public:
        Circle(const std::string_view&, double);
        ~Circle();
        auto getArea(void) const -> double;
        auto getRadius(void) -> double;
        auto setRadius(double r) -> void;
    private:
        double radius;
        static constexpr float PI = 3.14159;
};