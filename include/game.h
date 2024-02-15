#ifndef GAME_H
#define GAME_H
#include <stdexcept>

class Shape;
class Game {
  friend class Shape;

 public:
  Game();
  Game(int limit_left, int limit_right, int limit_down);
  Game(const Game &) = default;
  Game &operator=(Game &&) = delete;
  Game &operator=(const Game &) = delete;
  ~Game() = default;
  void draw();
  bool move_down();
  void shape_gen();
  void begain();

 private:
  int current_shape = 0;
  int derection = 0;
  int map[10][20] = {0};
  int shap_map[7][4][4][2] = {{{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                               {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
                               {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                               {{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
                              {{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
                               {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
                               {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
                               {{0, 1}, {1, 1}, {2, 1}, {2, 0}}}};
  int color[7] = {20, 30};
  int loc_x = 0;
  int loc_y = 0;
  int len_x;
  int len_y;
};

#endif  // !GAME_H