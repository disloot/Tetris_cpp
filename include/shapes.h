#ifndef SHAPES_H
#define SHAPES_H
#include <random>
#include <string>

#include "terminal.h"
using std::string;
enum class Derection { UP, DOWN, LIGHT, RIGHT };

class Shape {
 public:
  Shape() = default;
  Shape(Shape &&) = default;
  Shape(const Shape &) = default;
  Shape &operator=(Shape &&) = default;
  Shape &operator=(const Shape &) = default;
  ~Shape() = default;
  virtual void display() const = 0;
  void display(const string &shape) const;
  void move_to(int x, int y);
  friend void tc::move_to(int x, int y);
  friend void tc::set_fore_color(int color);
  friend void tc::set_back_color(int color);
  friend void tc::clear_screen();
  friend void tc::reset_color();
  friend void tc::hide_cursor();
  friend void tc::show_cursor();

 protected:
  int x = 0;
  int y = 0;
  Derection derection = Derection::UP;
  int color = 15;
  string shape = " ";

 private:
};

class Long : public Shape {
 public:
  Long() = default;
  ~Long() = default;
  void go_down(int speed);

 private:
  int color = 20;
  string shape = "    ";
};

class LShape : public Shape {
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
  string shape = "  \n ";
};

#endif  // !SHAPES_H