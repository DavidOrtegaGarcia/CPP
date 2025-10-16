#include "ShrubberyCreationForm.hpp"

//ORTHODOX CANONICAL FORM
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return(*this);
}

//GETTERS
std::string ShrubberyCreationForm::getTarget() const
{
	return(_target);
}

//MEMBER FUNCTIONS
void ShrubberyCreationForm::executeForm() const
{
	std::ofstream file;
	std::string filename;

	filename = _target + "_shrubbery";
	file.open(filename.c_str(), std::ios::out);

	if (!file.is_open())
		std::cout << "Error: " << filename << " couldn't be opened" << std::endl;
	else
	{
		file << "                                               .\n"
				"                                    .         ;\n"
				"       .              .              ;%     ;;\n"   
				"         ,           ,                :;%  %;\n"   
				"          :         ;                   :;%;'     .,\n"   
				" ,.        %;     %;            ;        %;'    ,;\n"
				"   ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				"    %;       %;%;      ,  ;       %;  ;%;   ,%;'\n" 
				"     ;%;      %;        ;%;        % ;%;  ,%;'\n"
				"      `%;.     ;%;     %;'         `;%%;.%;'\n"
				"       `:;%.    ;%%. %@;        %; ;@%;%'\n"
				"          `:%;.  :;bd%;          %;@%;'\n"
				"            `@%:.  :;%.         ;@@%;'\n"   
				"              `@%.  `;@%.      ;@@%;\n"         
				"                `@%%. `@%%    ;@@%;\n"        
				"                  ;@%. :@%%  %@@%;\n"       
				"                    %@bd%%%bd%%:;\n"     
				"                      #@%%%%%:;;\n"
				"                      %@@%%%::;\n"
				"                      %@@@%(o);  . '\n"         
				"                      %@@@o%;:(.,'\n"         
				"                  `.. %@@@o%::;\n"         
				"                     `)@@@o%::;\n"         
				"                      %@@(o)::;\n"        
				"                     .%@@@@%::;\n"         
				"                     ;%@@@@%::;.\n"          
				"                    ;%@@@@%%:;;;.\n" 
				"                ...;%@@@@@%%:;;;;,..\n"  << std::endl;
		file.close();
	}
}