#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "ring.hpp"
#include "shapearray.hpp"
#include "scaleisotropically.hpp"
#include "printdata.hpp"
#include "inputarray.hpp"

int main()
{
  std::string name_shape = "";
  bool have_invalid_shape = false;
  bool is_scale = false;
  double scale_coef = 0.0;
  hrushchev::point_t scale_point{0.0, 0.0};
  size_t capacity = 10;
  size_t size = 0;
  hrushchev::Shape** shapes = new hrushchev::Shape*[capacity];

  do
  {
    hrushchev::Shape* shape = nullptr;
    try
    {
      if (size + 1 == capacity)
      {
        hrushchev::Shape** expanded_shapes = hrushchev::expandArray(shapes, capacity);
        capacity += 10;
        delete[] shapes;
        shapes = expanded_shapes;
      }

      std::cin >> name_shape;
      if (!std::cin)
      {
        break;
      }

      if (name_shape == "RECTANGLE")
      {
        double parameters[4]{};
        hrushchev::inputArray(std::cin, parameters, 4);
        shape = new hrushchev::Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
        shapes[size] = shape;
        size++;
      }
      if (name_shape == "CIRCLE")
      {
        double parameters[3]{};
        hrushchev::inputArray(std::cin, parameters, 3);
        shape = new hrushchev::Circle({parameters[0], parameters[1]}, parameters[2]);
        shapes[size] = shape;
        size++;
      }
      if (name_shape == "RING")
      {
        double parameters[4]{};
        hrushchev::inputArray(std::cin, parameters, 4);
        shape = new hrushchev::Ring({parameters[0], parameters[1]}, parameters[3], parameters[2]);
        shapes[size] = shape;
        size++;
      }
      if (name_shape == "SCALE")
      {
        is_scale = true;
        std::cin >> scale_point.x >> scale_point.y >> scale_coef;
        break;
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
      have_invalid_shape = true;
      continue;
    }
    catch (...)
    {
      std::cerr << "Error\n";
      hrushchev::deleteArray(shapes, size);
      return 1;
    }
  }
  while (std::cin);
  if (is_scale && size > 0)
  {
    hrushchev::printData(std::cout, shapes, size);
    std::cout << "\n";
    try
    {
      for (size_t i = 0; i < size; i++)
      {
        hrushchev::scaleIsotropically(shapes[i], scale_point, scale_coef);
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
      hrushchev::deleteArray(shapes, size);
      return 1;
    }
    hrushchev::printData(std::cout, shapes, size);
    std::cout << "\n";
    if (have_invalid_shape)
    {
      std::cerr << "some figure is invalid\n";
    }
    hrushchev::deleteArray(shapes, size);
  }
  else
  {
    hrushchev::deleteArray(shapes, size);
    std::cerr << "Somthing wrong\n";
    return 1;
  }
}

