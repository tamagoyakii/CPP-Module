#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
	private:
		std::vector<int> _vector;
		unsigned int _size;
		Span(void);
	public:
		Span(unsigned int n);
		Span(const Span& ref);
		Span& operator=(const Span& ref);
		~Span(void);

		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);

	class FullElementsException : public std::exception {
		public:
			const char* what() const throw();
	};

	class NeedMoreNumbersException : public std::exception {
		public:
			const char* what() const throw();
	};
};

#endif