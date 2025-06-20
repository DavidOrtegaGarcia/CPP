#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _sgrade;
		const int _egrade;
	public:
		Form();
		Form(std::string name, int sgrade, int egrade);
		Form(const Form &other);
		~Form();
		Form &operator = (const Form &other);

		std::string	getName() const;
		bool 		getSigned() const;
		int			getSgrade() const;
		int			getEgrade() const;

		void beSigned(const Bureaucrat &bur);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException :public std::exception{
			public:
				const char* what() const throw();
		};
};
std::ostream &operator << (std::ostream &out, const Form &form);