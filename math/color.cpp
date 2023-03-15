#include "color.h"

Color::Color()
    : Tuple(0, 0, 0, 0)
{

}

Color::Color(float x, float y, float z)
    : Tuple(x, y, z, 0)
{
}

Color operator*(Color c1, Color c2)
{
    float x = c1.x() * c2.x();
    float y = c1.y() * c2.y();
    float z = c2.z() * c2.z();
    return Color(x, y, z);
}
