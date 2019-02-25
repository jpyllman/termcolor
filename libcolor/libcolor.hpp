#if !defined(LIBCOLOR_HPP)
#define LIBCOLOR_HPP

#include <cstdint>

namespace libcolor {

struct RGB {
  std::uint8_t red;
  std::uint8_t green;
  std::uint8_t blue;
};

double contrast(RGB c1, RGB c2);

} // namespace libcolor

#endif // !defined(LIBCOLOR_HPP)
