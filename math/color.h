#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

class Color : public Tuple
{
public:
    Color();
    Color(float x, float y, float z);

};

inline Color operator*(Color c1, Color c2);
#endif // COLOR_H
