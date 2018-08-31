//
// EPITECH PROJECT, 2018
// Dispatch.hpp
// File description:
// Dispatch header for the plazza
//

#include <vector>
#include <list>
#include <utility>
#include <string>
#include <iostream>
#include "Pipe.hpp"

class Dispatch
{
public:
	Dispatch(int threads_nb);
	~Dispatch();

	void	launchFork();
	void	Algo(std::list <std::pair<std::list<std::string>, int>> cmd);
	void	clearPipes();

private:
	std::vector<Pipe*>	childs;
	std::vector<int>	count;
	unsigned int		cur_idx;
	int			_threads_nb;
};
