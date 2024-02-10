
#include "game.h"

#include "shapes.h"

Game::Game(int limit_left, int limit_right, int limit_down)
    : current_shape(nullptr) {
  Shape::limit_left = limit_left;
  Shape::limit_right = limit_right;
  Shape::limit_down = limit_down;
}
