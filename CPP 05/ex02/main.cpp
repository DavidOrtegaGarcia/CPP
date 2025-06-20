#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "IS NOT SIGNED TEST" << std::endl;
	ShrubberyCreationForm scf("SFC");
	Bureaucrat bur = Bureaucrat("David", 138);
	std::cout << scf << std::endl;
	bur.executeForm(scf);
	std::cout << std::endl;
	
	std::cout << "TOO LOW TO EXECUTE GRADE TEST:" << std::endl;
	scf.beSigned(bur);
	std::cout << scf << std::endl;
	bur.executeForm(scf);
	std::cout << std::endl;
	
	std::cout << "SHRUBBERY CREATION FORM TEST:" << std::endl;
	bur = Bureaucrat("David", 1);
	std::cout << scf << std::endl;
	bur.executeForm(scf);
	std::cout << std::endl;

	std::cout << "ROBOTOMY REQUEST FORM TEST:" << std::endl;
	RobotomyRequestForm rrf("RRF");
	rrf.beSigned(bur);
	std::cout << rrf << std::endl;
	bur.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "PRESIDENTAL PARDON FORM TEST:" << std::endl;
	PresidentialPardonForm ppf("PPF");
	ppf.beSigned(bur);
	std::cout << ppf << std::endl;
	bur.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "TESTS FINISHED" << std::endl;

}