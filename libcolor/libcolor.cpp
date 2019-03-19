#include "libcolor.hpp"

#include <cmath>

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
  double contrast_ = 0.0;

  double r1 = x2sRGB(c1.red / 255.0);
  double g1 = x2sRGB(c1.green / 255.0);
  double b1 = x2sRGB(c1.blue / 255.0);

  double l1 = 0.2126 * r1 + 0.7152 * g1 + 0.0722 * b1;

  double r2 = x2sRGB(c2.red / 255.0);
  double g2 = x2sRGB(c2.green / 255.0);
  double b2 = x2sRGB(c2.blue / 255.0);

  double l2 = 0.2126 * r2 + 0.7152 * g2 + 0.0722 * b2;

  contrast_ = (l1 + 0.05) / (l2 + 0.05);

  return contrast_;
}

} // namespace libcolor
