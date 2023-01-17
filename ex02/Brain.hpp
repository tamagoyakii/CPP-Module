#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain(std::string idea);
		Brain(const Brain& ref);
		Brain& operator=(const Brain& ref);
		~Brain(void);
		std::string getIdea(int i) const;
};

#endif