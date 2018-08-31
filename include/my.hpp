//
// EPITECH PROJECT, 2018
// my.h
// File description:
// utils and other header
//

#ifndef MY_HPP_
# define MY_HPP_

#include <list>
#include <iostream>
#include <cstring>
#include <cstdlib>

#define KO	84
#define OK	0

#define RED	"\033[1;31m"
#define GREEN	"\033[1;32m"
#define PURPLE	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define BROWN	"\033[0;33m"
#define BLUE	"\033[1;34m"
#define YELLOW	"\033[1;33m"
#define BLANK	"\033[0m"

std::string	epur_str(std::string);
void		print_help();
int		check_semi(std::string str);
void		check_file(std::list<std::string> *str);

#endif /* MY_HPP_ */
