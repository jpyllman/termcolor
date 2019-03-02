#include <fmt/color.h>
#include <fmt/printf.h>

constexpr static fmt::terminal_color clr_arr[] = {
    fmt::terminal_color::black,        fmt::terminal_color::red,
    fmt::terminal_color::green,        fmt::terminal_color::yellow,
    fmt::terminal_color::blue,         fmt::terminal_color::magenta,
    fmt::terminal_color::cyan,         fmt::terminal_color::white,
    fmt::terminal_color::bright_black, fmt::terminal_color::bright_red,
    fmt::terminal_color::bright_green, fmt::terminal_color::bright_yellow,
    fmt::terminal_color::bright_blue,  fmt::terminal_color::bright_magenta,
    fmt::terminal_color::bright_cyan,  fmt::terminal_color::bright_white};

void preview_output() {
  for (auto &fgclr : clr_arr) {
    for (auto &bgclr : clr_arr) {
      fmt::print(fmt::fg(fgclr) | fmt::bg(bgclr), " jYp ");
    }
    fmt::print("\n");
  }
}

int main(int, char *[], char *[]) { preview_output(); }
