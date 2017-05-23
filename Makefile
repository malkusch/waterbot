
clean:
	rm -f test/tests

compile-tests:
	g++ -I test/src/ -I libraries/ -I . -I test/libraries/Catch/include \
	test/src/tests.cpp -o test/tests

test: compile-tests
	./test/tests

