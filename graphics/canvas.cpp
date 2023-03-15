#include "canvas.h"

unsigned int Canvas::width() const
{
    return m_width;
}

unsigned int Canvas::height() const
{
    return m_height;
}

std::string Canvas::toPPM()
{
    std::string out = "P3\n";
    out += std::to_string(m_width) + " ";
    out += std::to_string(m_height) + "\n255\n";

    auto clampColor = [](int &c)
    {
        if (c < 0)
            c = 0;
        else if (c > 255)
            c = 255;
    };

    for (unsigned int y = m_height; y > 0; y--)
    {
        for (unsigned int x = 0; x < m_width; x++)
        {
            Color c = pixelAt(x, y);
            int r = c.x() * 255;
            clampColor(r);
            int g = c.y() * 255;
            clampColor(g);
            int b = c.z() * 255;
            clampColor(b);
            out += std::to_string(r) + " ";
            out += std::to_string(g) + " ";
            out += std::to_string(b) + "\n";
        }
    }
    out += "\n";
    return out;
}

Canvas::Canvas(unsigned int w, unsigned int h)
    : m_width(w),
      m_height(h)
{
    m_pixels = new Color[w * h];
    clear(Color(0, 0, 0));
}

Canvas::~Canvas()
{
    delete m_pixels;
}

void Canvas::setPixelAt(unsigned int x, unsigned int y, Color c)
{
    if (x >= m_width || y >= m_height || x < 0 || y < 0)
        return;
    unsigned int offset = m_width * y + x;
    m_pixels[offset] = c;
}

Color Canvas::pixelAt(unsigned int x, unsigned int y)
{
    if (x >= m_width || y >= m_height || x < 0 || y < 0)
        return Color(0, 0, 0);
    unsigned int offset = m_width * y + x;
    return m_pixels[offset];
}

void Canvas::clear(Color c)
{
    for (unsigned int i = 0; i < m_width * m_height; i++)
    {
        m_pixels[i] = c;
    }
}
