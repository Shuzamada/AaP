#include "printdata.hpp"
#include <iomanip>
#include <ostream>
#include <cstddef>
#include "shape.hpp"

void hrushchev::printData(std::ostream& out, const hrushchev::Shape* const* shapes, const size_t size)
{
  out << std::fixed << std::setprecision(1);
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum += shapes[i]->getArea();
  }
  out << sum;

  hrushchev::rectangle_t frame_rectangle{};
  for (size_t i = 0; i < size; i++)
  {
    out << " ";
    frame_rectangle = shapes[i]->getFrameRectangle();
    double x1 = frame_rectangle.pos.x - frame_rectangle.width / 2;
    double y1 = frame_rectangle.pos.y - frame_rectangle.height / 2;
    double x2 = frame_rectangle.pos.x + frame_rectangle.width / 2;
    double y2 = frame_rectangle.pos.y + frame_rectangle.height / 2;
    out << x1 << " " << y1 << " " << x2 << " " << y2;
  }
}

