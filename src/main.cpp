#include <iostream>
#include <ostream>
#include <thread>

#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;
int main(int argc, const char** argv) {
  tc::hide_cursor();
  LShape l;
  LongShape longshape(1, 5);
  for (auto i = 1; i < 10; i++) {
    l.move_down();
    l.move_right();
    std::this_thread::sleep_for(500ms);
  }
  for (auto i = 1; i < 10; i++) {
    longshape.move_down();
    longshape.move_left();
    std::this_thread::sleep_for(500ms);
  }
  tc::show_cursor();
}