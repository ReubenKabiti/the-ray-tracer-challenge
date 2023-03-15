#include <iostream>
#include "math/tuple.h"
#include "graphics/canvas.h"

#include <vector>
#include <fstream>

namespace tests
{
}

namespace ProjectileFun
{
struct Projectile
{
    Tuple m_position;
    Tuple m_velocity;
    Projectile(Tuple position, Tuple velocity)
    {
        m_position = position;
        m_velocity = velocity;
    }
    inline const Tuple &position() const
    {
        return m_position;
    }
    inline const Tuple &velocity() const
    {
        return m_velocity;
    }


};

struct Environment
{
    Tuple m_gravity;
    Tuple m_wind;

    Environment(Tuple gravity, Tuple wind)
    {
       m_gravity = gravity;
       m_wind = wind;
    }

    inline const Tuple &gravity()
    {
        return m_gravity;
    }
    inline const Tuple &wind()
    {
        return m_wind;
    }
};

Projectile tick(Environment e, Projectile p)
{
    Tuple position = p.position() + p.velocity();
    Tuple velocity = p.velocity() + e.gravity() + e.wind();
    return Projectile(position, velocity);
}

}

using namespace ProjectileFun;

int main()
{
    Projectile p(Tuple::point(0, 1, 0), Tuple::normalize(Tuple::vector(1, 1, 0)) * 4);
    Environment e(Tuple::vector(0, -0.1, 0), Tuple::vector(-0.01, 0, 0));
    int numTicks = 0;

    Canvas c(200, 50);

    while (true)
    {
        p = tick(e, p);
        c.setPixelAt(p.position().x(), p.position().y(), Color(255, 255, 0));
        std::cout << "Position: (" << p.position().x()
                  << ", " << p.position().y()
                  << ", " << p.position().z()
                  << ", " << p.position().w()
                  << ")" << std::endl;
        if (p.position().y() <= 0)
            break;
        numTicks ++;
    }

    std::cout << "Number of ticks: " << numTicks << std::endl;
    std::ofstream stream;
    stream.open("image.ppm", std::ios::out);
    stream << c.toPPM();
    return 0;
}





