#ifndef GAME_H
#define GAME_H
#include "shapes.h"
class Game {
 public:
  Game() = delete;
  Game(int limit_left, int limit_right, int limit_down);
  Game(const Game &) = default;
  Game &operator=(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  ~Game() = default;
  void begain();
  void shape_gen();

 private:
  Shape *current_shape;
};

#endif  // !GAME_H