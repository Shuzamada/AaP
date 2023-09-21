#ifndef BASETYPES_HPP
#define BASETYPES_HPP
namespace hrushchev
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
  point_t changePoint(point_t point, double dx, double dy);
  point_t getSegmentCenter(point_t  p1, point_t p2);
}
#endif
