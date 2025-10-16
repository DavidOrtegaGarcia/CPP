#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator = (const RobotomyRequestForm &other);

		std::string getTarget() const;
		void executeForm() const;
};