#include "Brain.hpp"

Brain::Brain(std::string idea) {
	for (int i = 0; i < 100; i++) this->_ideas[i] = idea;
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& ref) {
	*this = ref;
	std::cout << "Brain copy created" << std::endl;
}

Brain& Brain::operator=(const Brain& ref) {
	for (int i = 0; i < 100; i++) this->_ideas[i] = ref.getIdea(i);
	std::cout << "Brain copied" << std::endl;
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed" << std::endl;
}

std::string Brain::getIdea(int i) const {
	if (i >= 0 && i < 100) return this->_ideas[i];
	return "";
}
