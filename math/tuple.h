#ifndef TUPLE_H
#define TUPLE_H
#include "helper.h"

#ifdef QT_DEBUG
#include <assert.h>
#else
#define assert(expr)
#endif

class Tuple
{
private:
    float m_x;
    float m_y;
    float m_z;
    float m_w;

public:
    Tuple();
    Tuple(float x, float y, float z, float w);

    float x() const;
    void setX(float newX);
    float y() const;
    void setY(float newY);
    float z() const;
    void setZ(float newZ);
    float w() const;
    void setW(float newW);


    inline static Tuple point(float x, float y, float z)
    {
        return Tuple(x, y, z, 1);
    }
    inline static Tuple vector(float x, float y, float z)
    {
        return Tuple(x, y, z, 0);
    }
    inline Tuple operator*(float a)
    {
        float x = m_x * a;
        float y = m_y * a;
        float z = m_z * a;
        float w = m_w * a;

        return Tuple(x, y, z, w);
    }

    inline Tuple operator/(float a)
    {
        return (*this) * (1.0f / a);
    }

    static float magnitude(Tuple t)
    {
        float m2 = t.x() * t.x() + t.y() * t.y() + t.z() * t.z() + t.w() * t.w();
        return fsqrt(m2);
    }
    static Tuple normalize(Tuple t)
    {
        float m = Tuple::magnitude(t);
        return t / m;
    }
    static float dot(Tuple t1, Tuple t2)
    {
        return t1.x() * t2.x() + t1.y() + t2.y() + t1.z() * t2.z() + t1.w() * t2.w();
    }
    static Tuple cross(Tuple a, Tuple b)
    {
        return Tuple::vector(
                 a.y() * b.z() - a.z() * b.y(),
                 a.z() * b.x() - a.x() * b.z(),
                 a.x() * b.y() - a.y() * b.x()
        );
    }
};

Tuple operator+(Tuple point, Tuple vector);
Tuple operator-(Tuple t1, Tuple t2);
Tuple operator-(Tuple t);
bool operator==(Tuple a, Tuple b);
#endif // TUPLE_H





