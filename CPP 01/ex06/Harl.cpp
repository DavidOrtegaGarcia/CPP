#include "Harl.hpp"

//PRIVATE FUNCTIONS
void Harl::debug(void)
{
	std::cout << "[ DEBUG ] \nI love having extra bacon for my " << 
	"7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << 
	std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ] \nI cannot believe adding extra bacon costs more money.\n" << 
	"You didn’t putenough bacon in my burger!" << 
	"If you did, I wouldn’t be asking for more!" << 
	std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ] \nI think I deserve to have some extra bacon for free.\n" << 
	"I’ve been coming for years whereas you started working here since last month." << 
	std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ] \nThis is unacceptable! I want to speak to the manager now." << 
	std::endl;
}

//PUBLIC
Harl::Harl(){}
Harl::~Harl(){}

void Harl::complain(std::string level)
{
	int i;
	std::string commands[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	i = 0;
	while(commands[i] != level && i < 4)
		i++;
	switch (i)
	{
		case 0:
			this->debug();
			std::cout << std::endl;
			/* fall through */
		case 1:
			this->info();
			std::cout << std::endl;
			/* fall through */
		case 2:
			this->warning();
			std::cout << std::endl;
			/* fall through */
		case 3:
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" <<
			std::endl;

		
	}
}
