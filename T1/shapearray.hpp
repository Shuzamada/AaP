#ifndef SHAPEARRAY_HPP
#define SHAPEARRAY_HPP
#include <cstddef>
#include "shape.hpp"

namespace hrushchev
{
  Shape** expandArray(Shape** shapes, size_t& capacity);
  void deleteArray(Shape** shapes, size_t capacity);
}
#endif

