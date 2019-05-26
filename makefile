run:
	g++ -o test functions.cpp main.cpp header.h student.h
unit_test:
	g++ -o test functions.cpp unit_test.cpp header.h catch.hpp
clean:
	rm -f *.txt test