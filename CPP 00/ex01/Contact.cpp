/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:15:03 by daortega          #+#    #+#             */
/*   Updated: 2024/10/11 15:06:39 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Constructors
Contact::Contact() 
{
	std::cout << "Default constructor Contact called" << std::endl;
}

Contact::~Contact() 
{
	std::cout << "Default destructor Contact called" << std::endl;
}

//Setters
void Contact::setFname(std::string fname)
{
	_fname = fname;
}

void Contact::setLname(std::string lname)
{
	_lname = lname;
}

void Contact::setNick(std::string nick)
{
	_nick = nick;
}

void Contact::setPhone(std::string phone)
{
	_phone = phone;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}

bool check_input_ds(std::string input)
{
	bool result = true;

	if (input[0] == '\0')
		return (false);
    for (int i = 0; input[i] != '\0'; i++)
	{
        if (input[i] == '\t' || input[i] == '\n' || input[i] == '\r' ||
			input[i] == '\v' || input[i] == '\f')
            result = false;
	}
    return (result);
}

bool check_input(std::string input)
{
	bool result = true;

	if (input[0] == '\0')
		return (false);
    for (int i = 0; input[i] != '\0'; i++)
	{
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' ||
			input[i] == '\r' || input[i] == '\v' || input[i] == '\f')
            result = false;
	}
    return (result);
}

void Contact::addContact()
{
	std::string str;

	do
	{
		std::cout << "First Name: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input(str));
	setFname(str);
	do
	{
		std::cout << "Last Name: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input(str));
	setLname(str);
	do
	{
		std::cout << "Nickname: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input(str));
	setNick(str);
	int i;
	do
	{
		std::cout << "Phone Number: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (!isdigit(str[i]))
				std::cout << "Phone Number can only have numbers!!!" << std::endl;
		}
		if (i != 9)
			std::cout << "Phone Number has to have 9 digits" << std::endl;
	} while(!check_input(str) && !exit);
	setPhone(str);
	do
	{
		std::cout << "Darkest secret: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input_ds(str));
	setDarkestSecret(str);
}

void printf_info(std::string str)
{
	int size;

	size = str.size();
	for (int i = 0; i < 10; i++){
		if (i < size) 
			std::cout << str[i];
		else
			std::cout << " ";
	}
	if (size > 10)
		std::cout << ".";
}

void Contact::printContact(int index)
{

	std::cout << "     " << index << "    |";
	printf_info(_fname);
	std::cout << "|";
	printf_info(_lname);
	std::cout << "|";
	printf_info(_nick);
	std::cout << std::endl;
}
