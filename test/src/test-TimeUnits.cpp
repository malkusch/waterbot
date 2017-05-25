#include <limits.h>
#include "catch.hpp"
#include "src/infrastructure/TimeUnits.cpp"
#include "Arduino.h"
#include "Arduino.cpp"

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

SCENARIO( "Calculate duration", "[TimeUnits::millisSince]" ) {
	GIVEN( "Time is 0" ){
		setMillis(0);
		WHEN( "Time difference is calculated" ) {
			THEN("") {
				REQUIRE(TimeUnits::millisSince(0) == 0);
				REQUIRE(TimeUnits::millisSince(ULONG_MAX) == 1);
				REQUIRE(TimeUnits::millisSince(ULONG_MAX - 999) == 1000);
			}
		}
	}
	GIVEN( "Time is 1" ){
		setMillis(1);
		WHEN( "Time difference is calculated" ) {
			THEN("") {
				REQUIRE(TimeUnits::millisSince(1) == 0);
				REQUIRE(TimeUnits::millisSince(0) == 1);
				REQUIRE(TimeUnits::millisSince(ULONG_MAX) == 2);
				REQUIRE(TimeUnits::millisSince(ULONG_MAX - 998) == 1000);
			}
		}
	}
	GIVEN( "Time is 1000" ){
		setMillis(1000);
		WHEN( "Time difference is calculated" ) {
			THEN("") {
				REQUIRE(TimeUnits::millisSince(0) == 1000);
				REQUIRE(TimeUnits::millisSince(999) == 1);
			}
		}
	}
	GIVEN( "Time is ULLONG_MAX" ){
		setMillis(ULONG_MAX);
		WHEN( "Time difference is calculated" ) {
			THEN("") {
				REQUIRE(TimeUnits::millisSince(ULONG_MAX) == 0);
				REQUIRE(TimeUnits::millisSince(ULONG_MAX - 1000) == 1000);
			}
		}
	}
}
