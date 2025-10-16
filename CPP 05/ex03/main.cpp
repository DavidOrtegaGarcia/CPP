#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		std::cout << "IS NOT SIGNED TEST" << std::endl;
		Intern someRandomIntern;
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Bureaucrat bur = Bureaucrat("David", 138);
		std::cout << scf << std::endl;
		bur.executeForm(*scf);
		std::cout << std::endl;

		std::cout << "TOO LOW TO EXECUTE GRADE TEST:" << std::endl;
		scf->beSigned(bur);
		std::cout << scf << std::endl;
		bur.executeForm(*scf);
		std::cout << std::endl;

		std::cout << "INTERN SHRUBBERY CREATION FORM TEST:" << std::endl;
		bur = Bureaucrat("David", 1);
		std::cout << scf << std::endl;
		bur.executeForm(*scf);
		delete(scf);
		std::cout << std::endl;

		std::cout << "INTERN ROBOTOMY REQUEST FORM TEST:" << std::endl;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(bur);
		std::cout << rrf << std::endl;
		bur.executeForm(*rrf);
		delete(rrf);
		std::cout << std::endl;

		std::cout << "INTERN PRESIDENTAL PARDON FORM TEST:" << std::endl;
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		ppf->beSigned(bur);
		std::cout << ppf << std::endl;
		bur.executeForm(*ppf);
		delete(ppf);
		std::cout << std::endl;

		std::cout << "INTERN ERROR FORM TEST:" << std::endl;
		AForm* err = someRandomIntern.makeForm("PATATA", "Bender");
		err->beSigned(bur);
		std::cout << err << std::endl;
		bur.executeForm(*err);
		std::cout << std::endl;
	} 
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "TESTS FINISHED" << std::endl;

}