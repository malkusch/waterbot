#include <limits.h>
#include "catch_with_main.hpp"
#include "src/infrastructure/TimeUnits.h"
#include "src/infrastructure/pin/cd74hc4067/CD74HC4067.h"
#include "Arduino.h"

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

SCENARIO( "Select channel", "[CD74HC4067::selectChannel]" ) {
	using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067;

	GIVEN( "A CD74HC4067 instance" ){
		byte ioPin = 1;
		byte s0Pin = 2;
		byte s1Pin = 3;
		byte s2Pin = 4;
		byte s3Pin = 5;
		byte ePin = 6;
		CD74HC4067 mux(ioPin, s0Pin, s1Pin, s2Pin, s3Pin, ePin);

		WHEN( "selecting channel 0" ) {
			mux.selectChannel(0);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 1" ) {
			mux.selectChannel(1);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 2" ) {
			mux.selectChannel(2);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 3" ) {
			mux.selectChannel(3);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 4" ) {
			mux.selectChannel(4);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 5" ) {
			mux.selectChannel(5);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 6" ) {
			mux.selectChannel(6);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 7" ) {
			mux.selectChannel(7);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 0);
			}
		}

		WHEN( "selecting channel 8" ) {
			mux.selectChannel(8);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 9" ) {
			mux.selectChannel(9);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 10" ) {
			mux.selectChannel(10);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 11" ) {
			mux.selectChannel(11);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 0);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 12" ) {
			mux.selectChannel(12);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 13" ) {
			mux.selectChannel(13);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 0);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 14" ) {
			mux.selectChannel(14);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 0);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}

		WHEN( "selecting channel 15" ) {
			mux.selectChannel(15);
			THEN("") {
				REQUIRE(getPinState(s0Pin) == 1);
				REQUIRE(getPinState(s1Pin) == 1);
				REQUIRE(getPinState(s2Pin) == 1);
				REQUIRE(getPinState(s3Pin) == 1);
			}
		}
	}
}


