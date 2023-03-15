#ifndef CANVAS_H
#define CANVAS_H
#include <string>
#include "math/color.h"


class Canvas
{
private:
    Color * m_pixels;

    unsigned int m_width;
    unsigned int m_height;

public:
    Canvas(unsigned int w, unsigned int h);
    ~Canvas();

    void setPixelAt(unsigned int x, unsigned int y, Color c);
    Color pixelAt(unsigned int x, unsigned int y);
    void clear(Color c);
    unsigned int width() const;
    unsigned int height() const;

    std::string toPPM();
};

#endif // CANVAS_H
