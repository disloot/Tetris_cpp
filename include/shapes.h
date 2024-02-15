#ifndef SHAPES_H
#define SHAPES_H
#include <string>

#include "game.h"
using std::string;
enum class Derection { UP, LEFT, DOWN, RIGHT };

class Shape {  // ToDo
  friend class Game;

 public:
  Shape() = default;
  Shape(Shape &&) = default;
  Shape(const Shape &) = default;
  Shape &operator=(Shape &&) = default;
  Shape &operator=(const Shape &) = default;
  ~Shape() = default;
  bool move_down();
  bool move_left();
  bool move_right();

 protected:
  Derection derection = Derection::LEFT;
  int color = 15;

 private:
};

class LongShape : public Shape {  // ToDo
 public:
  LongShape() = default;
  ~LongShape() = default;

 private:
  int color = 20;
  int map[4][4][2] = {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                      {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                      {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                      {{0, 0}, {0, 1}, {0, 2}, {0, 3}}};
};

class LShape : public Shape {  // ToDo
 public:
  LShape() = default;
  ~LShape() = default;

 private:
  int color = 75;
  int map[4][4][2] = {
      {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
      {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
      {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
  };
};
#endif  // !SHAPES_H