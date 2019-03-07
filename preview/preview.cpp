#include <clara/clara.hpp>

#include <fmt/color.h>
#include <fmt/printf.h>

static fmt::terminal_color clr_normal[] = {
    fmt::terminal_color::black, fmt::terminal_color::red,
    fmt::terminal_color::green, fmt::terminal_color::yellow,
    fmt::terminal_color::blue,  fmt::terminal_color::magenta,
    fmt::terminal_color::cyan,  fmt::terminal_color::white};

static fmt::terminal_color clr_bright[] = {
    fmt::terminal_color::bright_black, fmt::terminal_color::bright_red,
    fmt::terminal_color::bright_green, fmt::terminal_color::bright_yellow,
    fmt::terminal_color::bright_blue,  fmt::terminal_color::bright_magenta,
    fmt::terminal_color::bright_cyan,  fmt::terminal_color::bright_white};

void preview_output() {
  for (int i = 0; i < (sizeof(clr_normal) / sizeof(clr_normal[0])); ++i) {
    for (int j = 0; j < (sizeof(clr_normal) / sizeof(clr_normal[0])); ++j) {
      fmt::print(fmt::fg(clr_normal[i]) | fmt::bg(clr_normal[j]), " jYp ");
      fmt::print(" ");
    }
    fmt::print("\n");
    for (int j = 0; j < (sizeof(clr_normal) / sizeof(clr_normal[0])); ++j) {
      fmt::print(fmt::fg(clr_bright[i]) | fmt::bg(clr_normal[j]), " jYp ");
      fmt::print(" ");
    }
    fmt::print("\n");
  }
}

struct cli_data {
  bool show_help = false;
  bool show_version = false;
};

class cli_parse {
public:
  cli_parse() = default;
  cli_parse(cli_data &data);
  virtual ~cli_parse() = default;

  bool is_show_help() const { return data_.show_help; }
  bool is_show_version() const { return data_.show_version; }

protected:
  cli_data data_;
};

bool parse_CLI(int NOArgs, char *Args[], cli_data &data) {

  auto cli = clara::Help(data.show_help) |
             clara::Opt(data.show_version)["--version"]("version").optional();

  auto cli_result = cli.parse(clara::Args(NOArgs, Args));

  if (!cli_result) {
    fmt::print("CLI error: {}\n", cli_result.errorMessage());
    return false;
  }

  if (data.show_help) {
    std::ostringstream oss;
    oss << cli;
    fmt::print(oss.str());

    return false;
  }

  if (data.show_version) {
    fmt::print("preview v0.0\n");
    return false;
  }

  return true;
}

int main(int NOArgs, char *Args[], char *Envs[]) {
  cli_data config;
  if (parse_CLI(NOArgs, Args, config)) {
    preview_output();
  }
}
