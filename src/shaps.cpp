#include <iostream>
#include <ostream>

#include "shapes.h"
#include "terminal.h"
// shape --------------------------------------
void Shape::move_to(int x, int y) {
  this->x = x;
  this->y = y;
}
Shape::Shape(int x, int y) : x(x), y(y) {}
void Shape::move_down() {
  if (x < limit_down) x++;
  display();
}
void Shape::move_left() {
  if (y > limit_left) y--;
  display();
}
void Shape::move_right() {
  if (y < limit_right) y++;
  display();
}

// LongShape -----------------------------------
void LongShape::display() const {
  tc::clear_screen();
  tc::move_to(x, y);
  tc::set_back_color(color);
  std::cout << "        ";
  std::cout << std::flush;
  tc::reset_color();
}

// Lshape --------------------------------
void LShape::display() const {
  tc::clear_screen();
  tc::move_to(x, y);
  tc::set_back_color(color);
  std::cout << "  ";
  tc::move_to(x + 1, y);
  std::cout << "      ";
  std::cout << std::flush;
  tc::reset_color();
}
