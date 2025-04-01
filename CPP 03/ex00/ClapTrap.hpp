#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int			_hp;
		int			_ep;
		int 		_attackDMG;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap &operator = (const ClapTrap &other);

		std::string getName() const;
		int 		getHP() const;
		int			getEP() const;
		int			getAttackDMG() const;
		void		setName(std::string const name);
		void		setHP(int const hp);
		void		setEP(int const ep);
		void		setAttackDMG(int const attack);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif