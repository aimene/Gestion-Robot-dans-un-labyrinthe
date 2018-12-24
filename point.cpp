#include<iostream>
#include<cmath>

#include"point.h"

namespace geom
{

point::point() : point {0.0,0.0}
{}

point::point(double x, double y) : d_x{x}, d_y{y}
{}

point point::cartesian(double x, double y)
{
  return {x,y};
}

point point::polar(double rho, double theta)
{
  return {rho*std::cos(theta),rho*std::sin(theta)};
}

double point::x() const
{
  return d_x;
}

double point::y() const
{
  return d_y;
}

double point::distance(const point& p) const
{
  double dx = p.d_x-d_x, dy = p.d_y-d_y;
  return std::sqrt(dx*dx + dy*dy);
}

//determinant |p1p2,p1p3|
double point::determinant(const point& p1, const point& p2, const point& p3)
{
  return (p2.d_x-p1.d_x)*(p3.d_y-p1.d_y) - (p2.d_y-p1.d_y)*(p3.d_x-p1.d_x);
}

//p above (p1,p2) <=> determinant(p1,p2,p)>0
bool point::above(const point& p1, const point& p2) const
{
  return determinant(p1,p2,*this) > 0.0;
}

bool point::below(const point& p1, const point& p2) const
{
  return determinant(p1,p2,*this) < 0.0;
}

//[p1,q1] cuts [p2,q2] <=> p1 and q1 are on opposite sides of (p2,q2)
//and p2 and q2 are on opposite sides of (p1,q1)

bool point::intersection(const point& p1, const point& q1,
                         const point& p2, const point& q2)
{
  return (p1.above(p2,q2) == q1.below(p2,q2) &&
          p2.above(p1,q1) == q2.below(p1,q1));
}

void point::moveTo(double x, double y)
{
  d_x = x; d_y = y;
}

void point::move(double dx, double dy)
{
  d_x += dx; d_y += dy;
}

point& point::operator*=(double val)
{
  d_x *= val; d_y *= val;
  return *this;
}

point operator*(double val, const point& p)
{
  point res{p};
  res *= val;
  return res;
}

point& point::operator/=(double val)
{
  d_x /= val; d_y /= val;
  return *this;
}

point point::operator/(double val) const
{
  point res{*this};
  res /= val;
  return res;
}

point& point::operator+=(const point& p)
{
  d_x += p.d_x; d_y += p.d_y;
  return *this;
}

point point::operator+(const point& p) const
{
  point res{*this};
  res += p;
  return res;
}

bool point::operator==(const point& p) const
{
  return (d_x == p.d_x) && (d_y == p.d_y);
}

bool point::operator!=(const point& p) const
{
  return (d_x != p.d_x) || (d_y != p.d_y);
}

void point::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void point::read(std::istream& ist)
{
  char c;
  ist>>c;
  if (c == '(')
  {
    double x;
    ist>>x>>c;
    if (c == ',')
    {
      double y;
      ist>>y>>c;
      if (c == ')') { d_x = x; d_y = y; }
    }
  }
}

std::ostream& operator<<(std::ostream& ost, const point& p)
{
  p.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, point& p)
{
  p.read(ist);
  return ist;
}

}
