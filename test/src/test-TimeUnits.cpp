#include <limits.h>
#include "catch.hpp"
#include "src/infrastructure/TimeUnits.cpp"

TEST_CASE( "Convert s into ms", "[TimeUnits::secondsToMillis]" ) {
	REQUIRE(TimeUnits::secondsToMillis(0) == 0);
	REQUIRE(TimeUnits::secondsToMillis(1) == 1000);
	REQUIRE(TimeUnits::secondsToMillis(4294920) == 4294920000);
	REQUIRE(TimeUnits::secondsToMillis(UINT_MAX) == (long) UINT_MAX * 1000);
}

TEST_CASE( "Convert m into ms", "[TimeUnits::minutesToMillis]" ) {
	REQUIRE(TimeUnits::minutesToMillis(0) == 0);
	REQUIRE(TimeUnits::minutesToMillis(1) == 60000);
	REQUIRE(TimeUnits::minutesToMillis(60) == 3600000);
	REQUIRE(TimeUnits::minutesToMillis(71582) == 4294920000);
}

TEST_CASE( "Convert h into ms", "[TimeUnits::hoursToMillis]" ) {
	REQUIRE(TimeUnits::hoursToMillis(0) == 0);
	REQUIRE(TimeUnits::hoursToMillis(1) == 3600000);
	REQUIRE(TimeUnits::hoursToMillis(1193) == 4294800000);
}

TEST_CASE( "Convert d into ms", "[TimeUnits::daysToMillis]" ) {
	REQUIRE(TimeUnits::daysToMillis(0) == 0);
	REQUIRE(TimeUnits::daysToMillis(1) == 86400000);
	REQUIRE(TimeUnits::daysToMillis(49) == 4233600000);
}
