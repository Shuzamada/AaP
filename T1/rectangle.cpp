#include "rectangle.hpp"
#include <stdexcept>
#include <cmath>

hrushchev::Rectangle::Rectangle(const hrushchev::point_t left_bottom, const hrushchev::point_t right_top):
  left_bottom_(left_bottom),
  right_top_(right_top)
{
  if (!isCorrectRectangle())
  {
    throw std::invalid_argument("Incorrect rectangle argument");
  }
}

double hrushchev::Rectangle::getArea() const
{
  return getFrameRectangle().height * getFrameRectangle().width;
}

hrushchev::rectangle_t hrushchev::Rectangle::getFrameRectangle() const
{
  point_t centre_frame_rect = getSegmentCenter(left_bottom_, right_top_);
  double height_frame_rect = right_top_.y - left_bottom_.y;
  double width_frame_rect = right_top_.x - left_bottom_.x;
  return {centre_frame_rect, width_frame_rect, height_frame_rect};
}

void hrushchev::Rectangle::move(const double dx, const double dy)
{
  left_bottom_ = changePoint(left_bottom_, dx, dy);
  right_top_  = changePoint(right_top_, dx, dy);
}

void hrushchev::Rectangle::move(const hrushchev::point_t position)
{
  point_t centre = getSegmentCenter(left_bottom_, right_top_);
  double dx = position.x - centre.x;
  double dy = position.y - centre.y;
  move(dx, dy);
}

void hrushchev::Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Incorrect scale coefficient");
  }
  point_t center = getFrameRectangle().pos;
  left_bottom_.x = center.x + (left_bottom_.x - center.x) * k;
  left_bottom_.y = center.y + (left_bottom_.y - center.y) * k;
  right_top_.x = center.x + (right_top_.x - center.x) * k;
  right_top_.y = center.y + (right_top_.y - center.y) * k;
}

bool hrushchev::Rectangle::isCorrectRectangle() const
{
  return ((left_bottom_.x < right_top_.x) && (left_bottom_.y < right_top_.y));
}

