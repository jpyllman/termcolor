#include "libcolor.hpp"

#include <cmath>
#include <limits>

namespace libcolor {

double x2sRGB(double x) {
  if (x < 0.04045) {
    x /= 12.92;
  } else {
    x = std::pow((x + 0.055) / 1.055, 2.4);
  }

  return x;
}

double contrast(RGB c1, RGB c2) {
  constexpr static double max_value = std::numeric_limits<RGB::prime_t>::max();

  double r1 = x2sRGB(c1.red / max_value);
  double g1 = x2sRGB(c1.green / max_value);
  double b1 = x2sRGB(c1.blue / max_value);

  double l1 = 0.2126 * r1 + 0.7152 * g1 + 0.0722 * b1;

  double r2 = x2sRGB(c2.red / max_value);
  double g2 = x2sRGB(c2.green / max_value);
  double b2 = x2sRGB(c2.blue / max_value);

  double l2 = 0.2126 * r2 + 0.7152 * g2 + 0.0722 * b2;

  return (l1 + 0.05) / (l2 + 0.05);
}

double euclidean_distance(RGB c1, RGB c2) {

  double dr = c1.red - c2.red;
  double dg = c1.green - c2.green;
  double db = c1.blue - c2.blue;

  return std::sqrt(dr * dr + dg * dg + db * db);
}

} // namespace libcolor
