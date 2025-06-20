#include "AForm.hpp"
#include "Bureaucrat.hpp"

//ORTHODOX CANONICAL FORM
AForm::AForm() : _name("Form1"), _signed(false), _sgrade(100), _egrade(75)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sgrade, int egrade) : _name(name), _signed(false), 
														_sgrade(sgrade), _egrade(egrade)
{
	std::cout << "AForm attributes constructor called" << std::endl;
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	else if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), 
								_sgrade(other._sgrade), _egrade(other._egrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator = (const AForm &other)
{								 
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return(*this);
}

//GETTERS
std::string	AForm::getName() const
{
	return(_name);	
}

bool 		AForm::getSigned() const
{
	return(_signed);
}

int			AForm::getSgrade() const
{
	return(_sgrade);
}

int			AForm::getEgrade() const
{
	return(_egrade);
}

//MEMBER FUNCTIONS
void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _sgrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (_signed == false)
		throw NotSignedException();
	if (executor.getGrade() > _egrade)
		throw GradeTooLowException();
	this->executeForm();
}

//EXCEPTIONS
const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade too HIGH");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too LOW");
}
const char* AForm::NotSignedException::what() const throw()
{
	return("Form not signed");
}

//OPERATORS
std::ostream &operator << (std::ostream &out, const AForm &form)
{
	return(out <<  form.getName() << " is signed?: "<< form.getSigned() << 
	", grade to sign: " << form.getSgrade() << 
	", grade to execute: " << form.getEgrade() << ".");
}