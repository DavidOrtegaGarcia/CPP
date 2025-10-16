#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _sgrade;
		const int _egrade;
	public:
		AForm();
		AForm(std::string name, int sgrade, int egrade);
		AForm(const AForm &other);
		virtual ~AForm();
		AForm &operator = (const AForm &other);

		std::string	getName() const;
		bool 		getSigned() const;
		int			getSgrade() const;
		int			getEgrade() const;

		void beSigned(const Bureaucrat &bur);
	 	void execute(Bureaucrat const & executor) const;
		virtual void executeForm() const = 0; // Virtual makes that sons CAN implement the function, 
											  // = 0 makes the class becomes abstact and that the sons HAVE to implement the function

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};
std::ostream &operator << (std::ostream &out, const AForm &form);