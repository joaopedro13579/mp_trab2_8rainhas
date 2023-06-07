#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "rainhas.hpp"


TEST_CASE("Se funciona") {
   REQUIRE(codigo("teste1.txt") == 0);
   REQUIRE(codigo("teste2.txt") == 1);
   REQUIRE(codigo("teste3.txt") == -1);
}
