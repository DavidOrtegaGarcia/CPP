/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:11 by daortega          #+#    #+#             */
/*   Updated: 2024/10/14 16:26:06 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstring>
#include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact _contacts[8];
		int n_contacts;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
};
#endif	