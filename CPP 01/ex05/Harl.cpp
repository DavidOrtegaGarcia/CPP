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
	void (Harl::*array[4])();

	array[0] = &Harl::debug;
	array[1] = &Harl::info;
	array[2] = &Harl::warning;
	array[3] = &Harl::error;
	
	i = 0;
	while(commands[i] != level && i < 4)
		i++;
	while(commands[i] == level)
	{
		(this->*array[i])();
		i++;
	}
}
