#if !defined(LIBCOLOR_HPP)
#define LIBCOLOR_HPP

#include <cstdint>

namespace libcolor {

struct RGB {
  typedef uint8_t prime_t;

  prime_t red;
  prime_t green;
  prime_t blue;
};

double contrast(RGB c1, RGB c2);

double euclidean_distance(RGB c1, RGB c2);

} // namespace libcolor

#endif // !defined(LIBCOLOR_HPP)
