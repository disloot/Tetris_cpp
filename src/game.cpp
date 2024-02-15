
#include "game.h"

#include <chrono>
#include <iostream>
#include <random>
#include <ratio>
#include <thread>

#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;
enum class ShapeName {
  LongShape,
  LShape,
};
Game::Game()
    : len_x(sizeof(map) / sizeof(map[0])),
      len_y(sizeof(map[0]) / sizeof(int)) {}
void Game::draw() {
  tc::clear_screen();
  for (auto i = 0; i < len_y; i++) {
    for (auto j = 0; j < len_x; j++) {
      tc::display_at(j + 1, i + 1, map[j][i]);
    }
  }
}
bool Game::move_down() {
  for (auto i = 0; i < 4; i++) {
    map[loc_x + shap_map[current_shape][derection][i][0]]
       [loc_y + shap_map[current_shape][derection][i][1]] = 0;
  }
  for (auto i = 0; i < 4; i++) {
    if (loc_y + shap_map[current_shape][derection][i][1] + 1 >= len_y ||
        map[loc_x + shap_map[current_shape][derection][i][0]]
           [loc_y + shap_map[current_shape][derection][i][1] + 1] != 0) {
      for (auto i = 0; i < 4; i++) {
        map[loc_x + shap_map[current_shape][derection][i][0]]
           [loc_y + shap_map[current_shape][derection][i][1]] =
               color[current_shape];
      }
      return false;
    }
  }
  for (auto i = 0; i < 4; i++) {
    map[loc_x + shap_map[current_shape][derection][i][0]]
       [loc_y + shap_map[current_shape][derection][i][1] + 1] =
           color[current_shape];
  }
  loc_y++;
  return true;
}
void Game::shape_gen() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);
  current_shape = dis(gen);
  loc_x = 4;
  loc_y = 0;
}
void Game::begain() {
  while (true) {
    shape_gen();
    while (move_down()) {
      draw();
      std::this_thread::sleep_for(100ms);
    }
    draw();
  }
}