#include "circle.hpp"
#include <stdexcept>

hrushchev::Circle::Circle(const hrushchev::point_t center, const double radius):
  center_(center),
  radius_(radius)
{
  if (!isCorrectCircle())
  {
    throw std::invalid_argument("Incorrect circle argument");
  }
}

double hrushchev::Circle::getArea() const
{
  return (3.14f * radius_ * radius_);
}

hrushchev::rectangle_t hrushchev::Circle::getFrameRectangle() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void hrushchev::Circle::move(double dx, double dy)
{
  center_ = hrushchev::changePoint(center_, dx, dy);
}

void hrushchev::Circle::move(hrushchev::point_t position)
{
  center_ = position;
}

void hrushchev::Circle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  radius_ *= k;
}

bool hrushchev::Circle::isCorrectCircle() const
{
  return radius_ > 0;
}

