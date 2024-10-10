/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:46:24 by daortega          #+#    #+#             */
/*   Updated: 2024/10/08 18:19:59 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int j = 1; argv[j] != NULL; j++)
		{
			for(int i = 0; argv[j][i] != '\0'; i++)
				argv[j][i] = toupper(argv[j][i]);
			std::cout << argv[j];
		}
		std::cout << std::endl;
	}
	return 0;
}

//std::endl == Macro para salto de linea