#include "cases.h"
namespace gestionRobotTerrain
{
cases::cases(int segment):d_segment{segment}
{}
cases::~cases()
{}
int cases::segment() const
{
    return d_segment;
}
void cases::changeSegment(int segment)
{
    d_segment = segment;
}
}

