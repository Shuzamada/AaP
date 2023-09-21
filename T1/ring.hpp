#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"
#include "circle.hpp"
namespace hrushchev
{
  class Ring: public Shape
  {
  public:
    Ring(point_t center, double small_radius, double big_radius);
    double getArea() const override;
    rectangle_t getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    Circle small_circle_;
    Circle big_circle_;
  };
}
#endif

