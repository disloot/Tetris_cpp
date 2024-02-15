#include "terminal.h"

#include <iostream>

#define CSI "\033["
void tc::move_to(int x, int y) { std::cout << CSI << x << ';' << y << 'H'; }
void tc::set_fore_color(int color) {
  std::cout << CSI << "38;5;" << color << 'm';
}
void tc::set_back_color(int color) {
  std::cout << CSI << "48;5;" << color << 'm';
}
void tc::clear_screen() { std::cout << CSI << "2J"; }
void tc::reset_color() { std::cout << CSI << "0m"; }
void tc::hide_cursor() { std::cout << CSI << "?25l"; }
void tc::show_cursor() { std::cout << CSI << "?25h"; }
void tc::display_at(int x, int y, int color) {
  tc::set_back_color(color);
  tc::move_to(y, x);
  std::wcout << " ";
  std::cout << std::flush;
  tc::reset_color();
}
