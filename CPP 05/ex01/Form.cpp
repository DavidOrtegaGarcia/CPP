#include "Form.hpp"
#include "Bureaucrat.hpp"

//ORTHODOX CANONICAL FORM
Form::Form() : _name("Form1"), _signed(false), _sgrade(100), _egrade(75)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sgrade, int egrade) : _name(name), _signed(false), 
														_sgrade(sgrade), _egrade(egrade)
{
	std::cout << "Form attributes constructor called" << std::endl;
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	else if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), 
								_sgrade(other._sgrade), _egrade(other._egrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator = (const Form &other)
{								 
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return(*this);
}

//GETTERS
std::string	Form::getName() const
{
	return(_name);	
}

bool 		Form::getSigned() const
{
	return(_signed);
}

int			Form::getSgrade() const
{
	return(_sgrade);
}

int			Form::getEgrade() const
{
	return(_egrade);
}

//MEMBER FUNCTIONS
void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _sgrade)
		throw GradeTooLowException();
	_signed = true;
}

//EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade too HIGH");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too LOW");
}

//OPERATORS
std::ostream &operator << (std::ostream &out, const Form &form)
{
	return(out <<  form.getName() << " is signed?: "<< form.getSigned() << 
	", grade to sign: " << form.getSgrade() << 
	", grade to execute: " << form.getEgrade() << ".");
}