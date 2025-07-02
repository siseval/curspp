#ifndef CURSPP_H
#define CURSPP_H

#include <string>
#include <curses.h>
#include <locale>
#include <cstdint>
#include "vec2.h"


namespace curspp {

enum color
{
    BLACK = 1,
    RED = 2,
    GREEN = 3,
    YELLOW = 4,
    BLUE = 5,
    MAGENTA = 6,
    WHITE = 7,
};
using color = enum color;

constexpr vec2::Vec2<int16_t> UP = vec2::Vec2<int16_t>{ 0, -1 };
constexpr vec2::Vec2<int16_t> DOWN = vec2::Vec2<int16_t>{ 0, 1 };
constexpr vec2::Vec2<int16_t> LEFT = vec2::Vec2<int16_t>{ -1, 0 };
constexpr vec2::Vec2<int16_t> RIGHT = vec2::Vec2<int16_t>{ 1, 0 };

void init();
void end();

inline void draw_pixel(const vec2::Vec2<int16_t> pos, const std::string pixel)
{
    mvaddstr(pos.y, pos.x, pixel.data());
}

inline void set_color(const enum color c)
{
    attron(COLOR_PAIR(c));
}

inline void set_bold(const bool enable)
{
    if (enable)
    {
        attron(A_BOLD);
    }
    else
    {
        attroff(A_BOLD);
    }
}

inline vec2::Vec2<int16_t> get_screen_size()
{
    int16_t width, height;
    getmaxyx(stdscr, height, width);
    return { width, height };
}

inline vec2::Vec2<int16_t> get_cursor_pos()
{
    int16_t x, y;
    getyx(stdscr, y, x);
    return { x, y };
}

inline char get_input()
{
    return getch();
}

inline void flush_input()
{
    flushinp();
}

inline void set_timeout_ms(int16_t ms)
{
    timeout(ms);
}

inline void refresh()
{
    refresh();
}

inline void clear_screen()
{
    erase();
}

}
#endif // CURSPP_H
