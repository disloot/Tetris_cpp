#include <iostream>
#include <ostream>

#include "shapes.h"
#include "terminal.h"
int Shape::limit_down = 0;
int Shape::limit_left = 0;
int Shape::limit_right = 0;
// shape --------------------------------------
void Shape::move_to(int x, int y) {
  this->x = x;
  this->y = y;
}
Shape::Shape(int x, int y) : x(x), y(y) {}
bool Shape::move_down() {
  if (x < Shape::limit_down) {
    x++;
    display();
    return true;
  }
  return false;
}
bool Shape::move_left() {
  if (y > Shape::limit_left) {
    y--;
    display();
    return true;
  }
  return false;
}
bool Shape::move_right() {
  if (y < limit_right) {
    y++;
    display();
    return true;
  }
  return false;
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
bool LongShape::move_right() {
  switch (derection) {
    case Derection::LEFT:
    case Derection::RIGHT:
      if (y + 3 < limit_right) {
        y++;
        display();
        return true;
      }
      return false;
    case Derection::DOWN:
    case Derection::UP:
      return Shape::move_right();
  }
}
void LongShape::change() {
  if (derection == Derection::LEFT) {
    derection = Derection::DOWN;
  } else if (derection == Derection::DOWN) {
    derection = Derection::LEFT;
  }
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
void LShape::change() {}
