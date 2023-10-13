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
    std::string_view getName() const;
};

#endif