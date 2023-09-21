#ifndef PRINTDATA_HPP
#define PRINTDATA_HPP
#include <ostream>
#include <cstddef>
#include "shape.hpp"
namespace hrushchev
{
  void printData(std::ostream& out, const Shape* const* shapes, size_t size);
}
#endif
