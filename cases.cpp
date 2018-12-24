#include "cases.h
namespace gestionRobotTerrain
{
cases::cases(double segment):d_segment{segment}
{}
cases::~cases()
{}
double cases::segment() const
{
    return d_segment;
}
void cases::changeSegment(double segment)
{
    d_segment = segment;
}
}

