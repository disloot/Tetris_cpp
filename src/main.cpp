#include <thread>

#include "game.h"
#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;

int main(int argc, const char** argv) {
  Game game(1, 20, 10);
  tc::hide_cursor();
  game.begain();
  // while (l.move_down()) {
  //   std::this_thread::sleep_for(500ms);
  // }

  tc::show_cursor();
}