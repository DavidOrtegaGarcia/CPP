#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.cpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator = (const Cat &other);

		void makeSound() const;
};

#endif