#include "catch_with_main.hpp"
#include "src/infrastructure/TimeUnits.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
	REQUIRE( TimeUnits::secondsToMillis(1) == 1000 );
}
