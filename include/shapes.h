#include "terminal.h"

class Shape {
 public:
  Shape(int x, int y, int color, int derection);
  Shape(Shape &&) = default;
  Shape(const Shape &) = default;
  Shape &operator=(Shape &&) = default;
  Shape &operator=(const Shape &) = default;
  ~Shape() = default;
  void move_to(int x, int y);
  void set_fore_color(int color);
  void set_back_color(int color);
  void clear_screen();
  void reset_color();
  void hide_cursor();
  void show_cursor();

 private:
};
