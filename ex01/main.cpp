#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void zoo(void) {
	Animal* animals[10];

	// 생성
	for (int i = 0; i < 5; i++) animals[i] = new Dog();
	for (int i = 5; i < 10; i++) animals[i] = new Cat();

	// 소리내기
	for (int i = 0; i < 10; i++) animals[i]->makeSound();
	
	// 소멸
	for (int i = 0; i < 10; i++) delete animals[i];

	// Cat c1;
	// Cat c2("Dog");

	// c1.showIdea(99);
	// c2.showIdea(99);

	// c1 = c2;

	// c1.showIdea(99);
	// c2.showIdea(99);

	// Dog d1("Cat");
	// Dog d2 = d1;

	// d2.showIdea(99);

	// Brain b("jihyukim");

	// d1.setBrain(b);

	// d1.showIdea(99);
	// d2.showIdea(99);
}

int main(void) {
	zoo();
	system("leaks a.out");

	return 0;
}