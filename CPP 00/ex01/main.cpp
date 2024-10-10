/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:36:14 by daortega          #+#    #+#             */
/*   Updated: 2024/10/10 16:14:22 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phone_book;
	std::string com; 

	do 
	{
		std::cout << "Write your command: "; 
			getline(std::cin, com);
		if (std::cin.eof())
		exit(1);
		if (com == "ADD")
			phone_book.add();

		else if (com == "SEARCH")
			phone_book.search();
		else
			std::cout << "Command not recognized" << std::endl;
	}while (com != "EXIT");
}
