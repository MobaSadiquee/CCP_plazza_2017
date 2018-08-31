//
// EPITECH PROJECT, 2018
// plazza.cpp
// File description:
// main plazza function
//

#include <unistd.h>
#include "Core.hpp"
#include "Cmd.hpp"
#include "Dispatch.hpp"

Plazza::Core::Core()
{}

Plazza::Core::~Core()
{}

void	Plazza::Core::prompt(Cmd cmd, int i)
{
	if (isatty(0))	{
		usleep(50000);
		if (cmd.getExit() == false)
			std::cout << GREEN << " [" << i << "] $> " << BLANK;
	}
}

int	Plazza::Core::initPlazza(int nbThreads)
{
	Dispatch	d(nbThreads);
	Cmd		cmd;
	int		i = 0;

	if (isatty(0))	{
		std::cout << YELLOW << "Welcome to the plazza" << BLANK << std::endl;
		std::cout << YELLOW << "Enter \"help\" to display help.\n" <<BLANK << std::endl;
		std::cout << GREEN << " [0] $> " << BLANK;
	}
	while (cmd.getExit() == false && std::getline(std::cin, _cmd)) {
		if (_cmd.empty() == false) {
			if ((cmd.get_cmd(this->_cmd)) == 0)
				d.Algo(cmd.getCmd());
			cmd.clearList();
		}
		if (cmd.getExit())
			d.clearPipes();
		++i;
		prompt(cmd, i);
	}
	return (OK);
}
