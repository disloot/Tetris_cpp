
#include "game.h"

#include <iostream>
#include <random>
#include <thread>
#include <utility>

#include "shapes.h"
using namespace std::chrono_literals;
using std::move;
enum class ShapeName {
  LongShape,
  LShape,
};

Game::Game(int limit_left, int limit_right, int limit_down) {
  shape_gen();
  Shape::limit_left = limit_left;
  Shape::limit_right = limit_right;
  Shape::limit_down = limit_down;
}
void Game::begain() {
  while (true) {
    while (current_shape->move_down()) {
      std::this_thread::sleep_for(500ms);
    }
    shape_gen();
  }
}
void Game::shape_gen() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis_shape(0, 1);
  std::uniform_int_distribution<> dis_direction(0, 3);
  auto shapename = static_cast<ShapeName>(dis_shape(gen));
  auto derection = static_cast<Derection>(dis_direction(gen));
  switch (shapename) {
    case ShapeName::LongShape:
      current_shape = new LongShape(0, 8);
      break;
    case ShapeName::LShape:
      current_shape = new LShape(0, 8);
      break;
  }
  switch (derection) {
    case Derection::DOWN:
      current_shape->derection = Derection::DOWN;
      break;
    case Derection::LEFT:
      current_shape->derection = Derection::LEFT;
      break;
    case Derection::RIGHT:
      current_shape->derection = Derection::RIGHT;
      break;
    case Derection::UP:
      current_shape->derection = Derection::UP;
      break;
  }
}
