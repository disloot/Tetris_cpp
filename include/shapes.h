#ifndef SHAPES_H
#define SHAPES_H
#include <random>
#include <string>

#include "terminal.h"
using std::string;
enum class Derection { UP, DOWN, LIGHT, RIGHT };

class Shape {  // ToDo
 public:
  Shape() = default;
  Shape(int x, int y);
  Shape(Shape &&) = default;
  Shape(const Shape &) = default;
  Shape &operator=(Shape &&) = default;
  Shape &operator=(const Shape &) = default;
  ~Shape() = default;
  virtual void display() const = 0;
  void move_to(int x, int y);
  void move_down();
  void move_left();
  void move_right();
  friend void tc::move_to(int x, int y);
  friend void tc::set_fore_color(int color);
  friend void tc::set_back_color(int color);
  friend void tc::clear_screen();
  friend void tc::reset_color();
  friend void tc::hide_cursor();
  friend void tc::show_cursor();

 protected:
  int x = 1;
  int y = 1;
  Derection derection = Derection::UP;
  int color = 15;
  static int limit_down;
  static int limit_left;
  static int limit_right;

 private:
};

class LongShape : public Shape {  // ToDo
 public:
  LongShape() = default;
  ~LongShape() = default;
  using Shape::Shape;
  void display() const override;

 private:
  int color = 20;
};

class LShape : public Shape {  // ToDo
 public:
  LShape() = default;
  LShape(LShape &&) = default;
  LShape(const LShape &) = default;
  LShape &operator=(LShape &&) = default;
  LShape &operator=(const LShape &) = default;
  ~LShape() = default;
  void display() const override;

 private:
  int color = 75;
};

#endif  // !SHAPES_H