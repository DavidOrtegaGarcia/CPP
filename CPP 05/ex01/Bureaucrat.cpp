#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Paco"), _grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat attributes constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return(_name);
}
int  Bureaucrat::getGrade() const
{
	return(_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception & e)
	{	
		std::cout << _name <<  " couldn't sign " <<  form.getName() << " because " << e.what() 
		<< std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high (<1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low (>150)");
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bur)
{
	return(out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".");
}