//
// EPITECH PROJECT, 2018
// main
// File description:
// main function for plazza project
//

#include <unistd.h>
#include <iostream>
#include "Core.hpp"
#include "Pipe.hpp"

int	check_args(int ac, char **av)
{
	if (ac != 2 || atoi(av[1]) <= 0) {
		std::cerr << RED << "\nUsage : ./plazza [threads_per_process]" << std::endl;
		std::cerr << "\tArgument should be an unsigned number.\n" << BLANK << std::endl;
		return (KO);
	}
	return (OK);
}

int	main(int ac, char **av)
{
	Plazza::Core	plazza;
	
	if (check_args(ac, av) == KO)
		return (KO);
	if ((plazza.initPlazza(atoi(av[1]))) == KO)
		return (KO);
	return (OK);
}
