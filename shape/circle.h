#include "abstractshape.h"

class Circle : Shape
{
    public:
        Circle(const std::string_view&, double);
        ~Circle();
        inline auto getArea(void) const -> double;
        inline auto getRadius(void) const -> double;
        auto setRadius(double r) -> void;
    private:
        double radius;
        static constexpr float PI = 3.14159;
};