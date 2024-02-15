#include <ncurses.h>

#include <thread>

#include "game.h"
#include "terminal.h"
using namespace std::chrono_literals;

int main() {
  Game game;
  game.begain();
  getch();
  return 0;
}
