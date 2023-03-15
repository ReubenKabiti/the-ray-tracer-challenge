#include "helper.h"

bool fequal(float a, float b)
{
    if (fabs(a - b) < EPSILON)
        return true;
    return false;
}
