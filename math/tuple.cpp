#include "tuple.h"

float Tuple::x() const
{
    return m_x;
}

void Tuple::setX(float newX)
{
    m_x = newX;
}

float Tuple::y() const
{
    return m_y;
}

void Tuple::setY(float newY)
{
    m_y = newY;
}

float Tuple::z() const
{
    return m_z;
}

void Tuple::setZ(float newZ)
{
    m_z = newZ;
}

float Tuple::w() const
{
    return m_w;
}

void Tuple::setW(float newW)
{
    m_w = newW;
}

Tuple operator+(Tuple point, Tuple vector)
{
    assert(fequal(vector.w(), 0));

    float x = point.x() + vector.x();
    float y = point.y() + vector.y();
    float z = point.z() + vector.z();
    float w = point.w() + vector.w();

    return Tuple(x, y, z, w);
}

Tuple operator-(Tuple t1, Tuple t2)
{
    float x = t1.x() - t2.x();
    float y = t1.y() - t2.y();
    float z = t1.z() - t2.z();
    float w = t1.w() - t2.w();

    return Tuple(x, y, z, w);
}

Tuple operator-(Tuple t)
{
    return Tuple::vector(0, 0, 0) - t;
}

Tuple::Tuple()
{
    m_x = m_y = m_z = m_w = 0;
}

Tuple::Tuple(float x, float y, float z, float w)
    : m_x(x),
      m_y(y),
      m_z(z),
      m_w(w)
{

}



