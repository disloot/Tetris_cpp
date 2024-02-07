#include <iostream>
#include <ostream>

#include "shapes.h"
#include "terminal.h"
void Shape::display(const string &shape) const {
  tc::clear_screen();
  tc::move_to(x, y);
  tc::set_back_color(color);
  std::cout << shape;
  std::cout << std::flush;
  tc::reset_color();
}
void Shape::move_to(int x, int y) {
  this->x = x;
  this->y = y;
}
void LShape::display() const { Shape::display(shape); }
