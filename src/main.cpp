#include <iostream>
#include <ostream>
#include <thread>

#include "terminal.h"
using namespace std::chrono_literals;
int main(int argc, const char** argv) {
  // tc::move_to(5, 10);
  // tc::set_fore_color(214);
  // std::cout << "hello" << std::endl;
  // tc::move_to(10, 1);
  tc::hide_cursor();
  for (auto i = 1; i <= 10; i++) {
    tc::clear_screen();
    tc::move_to(i, 10);
    tc::set_back_color(15);
    std::cout << "   ";
    tc::reset_color();
    std::cout << std::flush;
    std::this_thread::sleep_for(500ms);
  }
  return 0;
}