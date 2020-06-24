#include "libcolor.hpp"

#include <cmath>
#include <limits>

namespace libcolor {

namespace sRGB {
constexpr static double to_liniar_level = 0.04045;
constexpr static double from_liniar_level = 0.0031308;

constexpr static double liniar_delta = 12.92;
constexpr static double liniar_add = 0.055;
constexpr static double liniar_alpha = 1.055;
constexpr static double liniar_gamma = 2.4;

double to_liniar( double x )
{
  if( x < to_liniar_level ) return x / liniar_delta;
  return std::pow( ( x + liniar_add ) / liniar_alpha, liniar_gamma );
}

double from_liniar( double x )
{
  if( x < from_liniar_level ) return x * liniar_delta;
  return ( liniar_alpha * std::pow( x, 1 / liniar_gamma ) ) - liniar_add;
}

constexpr double red_grey = 0.2126;
constexpr double green_grey = 0.7152;
constexpr double blue_grey = 0.0722;

double liniar_to_grey( double r, double g, double b ) { return red_grey * r + green_grey * g + blue_grey * b; }
RGB grey_to_liniar( double /*unused*/ ) { return {0, 0, 0}; }

} // namespace sRGB

double contrast( RGB c1, RGB c2 )
{
  constexpr static double max_value = std::numeric_limits<RGB::prime_t>::max();

  double r1 = sRGB::to_liniar( c1.red / max_value );
  double g1 = sRGB::to_liniar( c1.green / max_value );
  double b1 = sRGB::to_liniar( c1.blue / max_value );

  double l1 = sRGB::liniar_to_grey( r1, g1, b1 );

  double r2 = sRGB::to_liniar( c2.red / max_value );
  double g2 = sRGB::to_liniar( c2.green / max_value );
  double b2 = sRGB::to_liniar( c2.blue / max_value );

  double l2 = sRGB::liniar_to_grey( r2, g2, b2 );

  constexpr static double avoid_div_zero = 0.05;
  return ( l1 + avoid_div_zero ) / ( l2 + avoid_div_zero );
}

double euclidean_distance( RGB c1, RGB c2 )
{

  double dr = c1.red - c2.red;
  double dg = c1.green - c2.green;
  double db = c1.blue - c2.blue;

  return std::sqrt( dr * dr + dg * dg + db * db );
}

} // namespace libcolor
