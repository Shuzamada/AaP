#include "inputarray.hpp"
#include <istream>
#include <cstddef>

void hrushchev::inputArray(std::istream& input, double* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> array[i];
  }
}

