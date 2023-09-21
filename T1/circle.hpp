#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
namespace hrushchev
{
  class Circle: public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRectangle() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;

  private:
    point_t center_;
    double radius_;
    bool isCorrectCircle() const;
  };
}
#endif

