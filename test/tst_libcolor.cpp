#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file
#include <catch2/catch.hpp>

#include <libcolor.hpp>

TEST_CASE("Calculate color contrast", "[libcolor]") {

  REQUIRE(libcolor::contrast({255, 255, 255}, {0, 0, 0}) == Approx(21.0));
  REQUIRE(libcolor::contrast({128, 128, 128}, {128, 128, 128}) == Approx(1.0));
  REQUIRE(libcolor::contrast({208, 48, 48}, {24, 24, 24}) == Approx(3.50681));
  REQUIRE(libcolor::contrast({254, 21, 4}, {24, 24, 24}) == Approx(4.50095));
  REQUIRE(libcolor::contrast({208, 48, 208}, {24, 24, 24}) == Approx(4.24085));
  REQUIRE(libcolor::contrast({220, 26, 229}, {24, 24, 24}) == Approx(4.50021));
}
