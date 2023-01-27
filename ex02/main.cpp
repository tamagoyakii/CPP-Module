#include "MutantStack.hpp"
#include <list>

int main(void) {
	std::cout << "-----------stack-----------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << ", ";

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	std::cout << "-----------list------------" << std::endl;
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << ", ";

	mlist.pop_back();
	std::cout << mstack.size() << std::endl;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		const int tmp = rand() % 10;
		mstack.push(tmp);
		mlist.push_back(tmp);
	}

	std::cout << "---------iter test---------" << std::endl;
	MutantStack<int>::iterator sit = mstack.begin();
	MutantStack<int>::iterator site = mstack.end();
	++sit;
	--sit;
	std::cout << "Stack : ";
	while (sit != site) {
		std::cout << *sit << ", ";
		++sit;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::list<int>::iterator lit = mlist.begin();
	std::list<int>::iterator lite = mlist.end();
	++lit;
	--lit;
	std::cout << "List  : ";
	while (lit != lite) {
		std::cout << *lit << ", ";
		++lit;
	}
	std::cout << std::endl;

	return 0;
}