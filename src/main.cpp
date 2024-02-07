#include <iostream>
#include <ostream>
#include <thread>

#include "shapes.h"
#include "terminal.h"
using namespace std::chrono_literals;
int main(int argc, const char** argv) {
  tc::hide_cursor();
  // for (auto i = 1; i <= 10; i++) {
  //   tc::clear_screen();
  //   tc::move_to(i, 10);
  //   tc::set_back_color(15);
  //   std::cout << "   ";
  //   std::cout << std::flush;
  //   tc::reset_color();
  //   std::this_thread::sleep_for(500ms);
  // }
  // Long Long;
  LShape l;
  l.move_to(1, 2);
  l.display();
}