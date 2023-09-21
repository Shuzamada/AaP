#include "basetypes.hpp"

hrushchev::point_t hrushchev::changePoint(hrushchev::point_t point, const double dx, const double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}

hrushchev::point_t hrushchev::getSegmentCenter(const hrushchev::point_t  p1, const hrushchev::point_t p2)
{
  double center_x = (p1.x + p2.x) / 2;
  double center_y = (p1.y + p2.y) / 2;
  return {center_x, center_y};
}

