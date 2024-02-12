#include <thread>

#include "game.h"
#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;

int main(int argc, const char** argv) {
  Game game(1, 20, 10);
  tc::hide_cursor();
  game.begain();

  tc::show_cursor();
}