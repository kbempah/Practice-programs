#ifndef shape_h
#define shape_h

#include <string>
#include <string_view>

class Shape
{
public:
    Shape(const std::string_view&);
    virtual ~Shape();
private:
    std::string name;
public:
    auto getName(void) -> std::string_view const;
    virtual auto getArea(void) const -> double = 0;
};

#endif