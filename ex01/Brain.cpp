#include "Brain.hpp"

Brain::Brain(std::string idea) {
	for (int i = 0; i < 100; i++) this->_ideas[i] = idea;
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& ref) {
	*this = ref;
	std::cout << "Brain copied" << std::endl;
}

Brain& Brain::operator=(const Brain& ref) {
	for (int i = 0; i < 100; i++) this->_ideas[i] = ref.getIdea(i);
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(const int i, const std::string idea) {
	this->_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
	if (i >= 0 && i < 100) return this->_ideas[i];
	return "";
}
