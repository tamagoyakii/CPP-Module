#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void): std::stack<T>() {}
		MutantStack(const MutantStack& ref) : std::stack<T>() {
			*this = ref;
		}
		MutantStack& operator=(const MutantStack& ref) {
			this->c = ref.c;
			return *this;
		}
		~MutantStack(void) {}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {
			return this->c.begin();
		}
		iterator end(void) {
			return this->c.end();
		}
};

#endif