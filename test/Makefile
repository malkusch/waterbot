all: test

clean:
	rm -f ./tests

compile-tests:
	g++ -I src/ -I ../libraries/ -I ../ -I libraries/Catch/include \
	src/tests.cpp -o tests

test: compile-tests
	./tests