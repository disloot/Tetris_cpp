#ifndef TERMINAL_H
#define TERMINAL_H

namespace tc {
void move_to(int x, int y);
void set_fore_color(int color);
void set_back_color(int color);
void clear_screen();
void reset_color();
void hide_cursor();
void show_cursor();
}  // namespace tc
#endif  // !TERMINAL_H