#include "ring.hpp"
#include <stdexcept>

hrushchev::Ring::Ring(hrushchev::point_t center, double small_radius, double big_radius):
  small_circle_(center, small_radius),
  big_circle_(center, big_radius)
{
  if ((small_radius > big_radius) || (small_radius <= 0) || (big_radius <= 0))
  {
     throw std::invalid_argument("Incorrect ring argument");
  }
}

double hrushchev::Ring::getArea() const
{
  return big_circle_.getArea() - small_circle_.getArea();
}

hrushchev::rectangle_t hrushchev::Ring::getFrameRectangle() const
{
  return big_circle_.getFrameRectangle();
}

void hrushchev::Ring::move(double dx, double dy)
{
  small_circle_.move(dx, dy);
  big_circle_.move(dx, dy);
}

void hrushchev::Ring::move(hrushchev::point_t position)
{
  small_circle_.move(position);
  big_circle_.move(position);
}

void hrushchev::Ring::scale(double k)
{
  small_circle_.scale(k);
  big_circle_.scale(k);
}

