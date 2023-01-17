#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;
	public:
		Cat(void);
		Cat(std::string idea);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		~Cat(void);

		void makeSound(void) const;
		void showIdea(int i) const;
};

#endif