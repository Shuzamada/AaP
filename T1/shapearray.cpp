#include "shapearray.hpp"
#include <cstddef>
#include "shape.hpp"

hrushchev::Shape** hrushchev::expandArray(hrushchev::Shape** shapes, size_t& capacity)
{
  hrushchev::Shape** expanded_shapes = new hrushchev::Shape*[capacity + 10];
  for (size_t i = 0; i < capacity; i++)
  {
    expanded_shapes[i] = shapes[i];
  }
  return expanded_shapes;
}

void hrushchev::deleteArray(hrushchev::Shape** shapes, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

