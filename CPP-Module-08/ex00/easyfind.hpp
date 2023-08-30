#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NoOccurrenceException : public std::exception {
	public:
		const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T& container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end()) throw NoOccurrenceException();
	return it;
}

#endif