#ifndef GAME_H
#define GAME_H
#include "shapes.h"
class Game {
 public:
  Game();
  Game(Game &&) = default;
  Game(const Game &) = default;
  Game &operator=(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  ~Game();

 private:
  Shape &current_shape;
};

#endif  // !GAME_H