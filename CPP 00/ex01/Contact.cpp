/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:15:03 by daortega          #+#    #+#             */
/*   Updated: 2024/10/14 16:24:10 by daortega         ###   ########.fr       */
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

bool check_input_name(std::string input, std:: string type)
{
	bool result = true;
	int i;

	if (input[0] == '\0')
		return (false);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' ||
			input[i] == '\r' || input[i] == '\v' || input[i] == '\f')
			result = false;
		if (!isalpha(input[i]) && result == true){
			std::cout << type << " can only have letters!!!" << std::endl;
			result = false;
		}
	}
	return (result);
}

bool check_input_phone(std::string input)
{
	bool result = true;
	int i;

	if (input[0] == '\0')
		return (false);
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' ||
			input[i] == '\r' || input[i] == '\v' || input[i] == '\f')
			result = false;
		if (!isdigit(input[i]) && result == true){
			std::cout << "Phone Number can only have numbers!!!" << std::endl;
			result = false;
		}
	}
	if (i != 9){
		std::cout << "Phone Number has to have 9 digits" << std::endl;
		result = false;
	}
	return (result);
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

void Contact::addContact()
{
	std::string str;

	do
	{
		std::cout << "First Name: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input_name(str, "Name"));
	setFname(str);
	do
	{
		std::cout << "Last Name: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input_name(str, "Last name"));
	setLname(str);
	do
	{
		std::cout << "Nickname: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input(str));
	setNick(str);
	do
	{
		std::cout << "Phone Number: ";
		getline(std::cin, str);
		if (std::cin.eof())
			exit(1);
	} while(!check_input_phone(str));
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
	if (size < 10){
		for (int i = 0; i < 10 - size; i++){
			std::cout << " ";
		}
	}
	for (int i = 0; i < 9 && i < size; i++){
		std::cout << str[i];
	}
	if (size > 10)
		std::cout << ".";
	else if (size == 10)
		std::cout << str[9];	
}

void Contact::printContact(int index)
{

	std::cout << "         " << index << "|";
	printf_info(_fname);
	std::cout << "|";
	printf_info(_lname);
	std::cout << "|";
	printf_info(_nick);
	std::cout << std::endl;
}

void Contact::printFullContact()
{
	std::cout << "First Name: "<< _fname << std::endl;
	std::cout << "Last Name: "<< _lname << std::endl;
	std::cout << "Nick: "<< _nick << std::endl;
	std::cout << "Phone Number: "<< _phone << std::endl;
	std::cout << "Darkest secret: "<< _darkest_secret << std::endl;
}
