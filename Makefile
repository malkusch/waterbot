
clean:
	rm -f test/tests

compile-tests:
	g++ -I test/src/ -I libraries/ -I . -I test/libraries/Catch/include \
	test/src/*.cpp src/infrastructure/TimeUnits.cpp \
	src/infrastructure/pin/cd74hc4067/CD74HC4067.cpp \
	-o test/tests

test: compile-tests
	./test/tests

