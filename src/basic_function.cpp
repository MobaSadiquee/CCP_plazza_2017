//
// EPITECH PROJECT, 2018
// basic_function.cpp
// File description:
// other & basic function for cpp
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "Core.hpp"

std::string	epur_str(std::string str)
{
	std::istringstream iss(str);
	std::string i, res;

	if (iss >> i)
		res += i;
	while (iss >> i)
		res += ' ' + i;
	return (res);
}

void	print_help()
{
	std::cout << CYAN << "Usage   :" << BLUE << "\t./plazza [number_of_threads_per_process]\n"
		  << BLANK << std::endl;
	std::cout << CYAN << "Commands:" << BLUE << "\n\thelp\tDisplay this help" << std::endl;
	std::cout << "\texit\tQuit the plazza" << BLANK << std::endl;
}

int	check_semi(std::string str)
{
	std::string::size_type i = 0;
	
	while (i < str.length()) {
		if (str[i] == ';' && str[i + 1] == ';')
			return (KO);
		i++;
	}
	return (OK);
}

void	check_file(std::list<std::string> *str)
{
	std::list<std::string>::iterator i = str->begin();

	while (i != str->end()) {
		if ((access(i->c_str(), F_OK) == -1)) {
			str->erase(i++);
		}
		else
			i++;
	}
}
