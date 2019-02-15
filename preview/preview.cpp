#include <cstring>
#include <iostream>

int main(int, char *[], char *[]) {
  std::cout << "           40m  41m  42m  43m  44m  45m  46m  47m\n";

  for (auto &x : {"    m", "   1m", "  30m", "1;30m", "  31m", "1;31m", "  32m",
                  "1;32m", "  33m", "1;33m", "  34m", "1;34m", "  35m", "1;35m",
                  "  36m", "1;36m", "  37m", "1;37m"}) {
    char const *z = x;
    for (; (*z != 0) && (*z == 0x20); ++z) {
    }

    std::cout << x << "\33[" << z << " gYw ";
    for (auto &y : {"40m", "41m", "42m", "43m", "44m", "45m", "46m", "47m"}) {
      std::cout << "\33[" << z << "\33[" << y << " gYw ";
    }

    std::cout << "\33[0m\n";
  }
}
