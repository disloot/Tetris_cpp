#include <iostream>
#include <ostream>
#include <thread>

#include "game.h"
#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;

int main(int argc, const char** argv) {
  Game game(1, 10, 5);
  tc::hide_cursor();
  LShape l;
  LongShape longshape(1, 5);

  // while (l.move_down()) {
  //   std::this_thread::sleep_for(500ms);
  // }
  for (auto x = 1; x < 10; x++) {
    longshape.change();
    longshape.move_down();

    std::this_thread::sleep_for(500ms);
  }
  tc::show_cursor();
}