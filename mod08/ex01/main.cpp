
#include "Span.hpp"
#include "print.hpp"
#include <list>
#include <vector>
#define INSERT_LEN 11000

int		main() {
	srand(time(nullptr));

	{
		Span sp = Span(5);
		try {
			std::cout << GREEN BOLD "Sbj tests" STD << std::endl;
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(15);
		} catch (std::exception & exc) {
			std::cout << RED << exc.what() << STD << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}

	std::cout << GREEN BOLD "Test constructors" STD << std::endl;
	std::cout << BOLD "Default + addNumber" STD << std::endl;
	Span span(5);
	try {
		span.addNumber(5231);
		span.addNumber(10432);
		span.addNumber(-12123);
		span.addNumber(-12123);
		span.addNumber(8);
	} catch (std::exception & exc) {
		std::cout << RED << exc.what() << STD << std::endl;
	}
	span.printSpan();

	std::cout << BOLD "Assignation operator" STD << std::endl;
	Span span1 = Span(1);
	span1.printSpan();
	try {
		span1.longestSpan();
	} catch (std::exception & exc) {
		std::cout << RED << exc.what() << STD << std::endl;
	}

	std::cout << BOLD "Copy constructor" STD << std::endl;
	Span span2(span);
	span2.printSpan();

	std::cout << std::endl << GREEN BOLD "Test insert" STD << std::endl;
	Span span3(10000);
	std::vector<int> myVector(INSERT_LEN);
	for (std::vector<int>::size_type i = 0; i < myVector.size(); i++) {
		myVector[i] = rand() % 40000;
	}
	std::cout << "Span len before insert: " << span3.getSize() << std::endl;
	try {
		std::cout << "Inserting 11000 nodes..." << std::endl;
		span3.addNumber(myVector.begin(), myVector.end());
		std::cout << "Span len after insert: " << span3.getSize() << std::endl;
		std::cout << "Shortest span: " << span3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span3.longestSpan() << std::endl;
	} catch (std::exception &exc) {
		std::cout << RED << exc.what() << STD << std::endl;
	}
//	span3.printSpan();

	return 0;
}
