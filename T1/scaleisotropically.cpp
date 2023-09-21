#include "scaleisotropically.hpp"
#include <stdexcept>
#include "shape.hpp"

void hrushchev::scaleIsotropically(hrushchev::Shape* shape, hrushchev::point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  double current_x = shape->getFrameRectangle().pos.x;
  double current_y = shape->getFrameRectangle().pos.y;
  double dx = point.x - current_x;
  double dy = point.y - current_y;
  shape->move(dx, dy);
  dx = -dx * k;
  dy = -dy * k;
  shape->scale(k);
  shape->move(dx, dy);
}
