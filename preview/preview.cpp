#include <clara/clara.hpp>

#include <fmt/color.h>
#include <fmt/printf.h>

#include <iostream>

static constexpr int NO_base_colors = 8;

static constexpr std::array<fmt::terminal_color, NO_base_colors> clr_normal = {
    fmt::terminal_color::black, fmt::terminal_color::red,     fmt::terminal_color::green, fmt::terminal_color::yellow,
    fmt::terminal_color::blue,  fmt::terminal_color::magenta, fmt::terminal_color::cyan,  fmt::terminal_color::white};

static constexpr std::array<fmt::terminal_color, NO_base_colors> clr_bright = {
    fmt::terminal_color::bright_black,  fmt::terminal_color::bright_red,  fmt::terminal_color::bright_green,
    fmt::terminal_color::bright_yellow, fmt::terminal_color::bright_blue, fmt::terminal_color::bright_magenta,
    fmt::terminal_color::bright_cyan,   fmt::terminal_color::bright_white};

static_assert(sizeof(clr_normal) == sizeof(clr_bright), "both color ranges need to bee same size");

void preview_output() {
  for (int i = 0; i < NO_base_colors; ++i) {
    for (auto &j : clr_normal) {
      fmt::print(fmt::fg(clr_normal[i]) | fmt::bg(j), " jYp ");
      fmt::print(" ");
    }
    fmt::print("\n");
    for (auto &j : clr_normal) {
      fmt::print(fmt::fg(clr_bright[i]) | fmt::bg(j), " jYp ");
      fmt::print(" ");
    }
    fmt::print("\n");
  }
}

struct cli_data {
  bool show_help = false;
  bool show_version = false;
};

bool parse_CLI(clara::Args const &args, cli_data &data) {

  auto cli = clara::Help(data.show_help) | clara::Opt(data.show_version)["--version"]("version").optional();

  auto cli_result = cli.parse(args);

  if (!cli_result) {
    fmt::print("CLI error: {}\n", cli_result.errorMessage());
    return false;
  }

  if (data.show_help) {
    fmt::print("{}", cli);
    return false;
  }

  if (data.show_version) {
    fmt::print("preview v{}\n", "0.0");
    return false;
  }

  return true;
}

int main(int NOArgs, char *Args[], char * /*Envs*/[]) {
  cli_data config;
  if (parse_CLI(clara::Args(NOArgs, Args), config)) {
    preview_output();
  }
}
