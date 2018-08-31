//
// EPITECH PROJECT, 2018
// Dispatch.cpp
// File description:
// Dispatch function for the plazza
//

#include <sstream>
#include <unistd.h>
#include "Dispatch.hpp"
#include "ThreadPool.hpp"

Dispatch::Dispatch(int threads_nb) : cur_idx(0), _threads_nb(threads_nb)
{
	
}

Dispatch::~Dispatch()
{

}

void	Dispatch::launchFork()
{
	childs.push_back(new Pipe);
	childs.back()->create(std::to_string(childs.size()));
	if (fork() == 0) {
		ThreadPool p(_threads_nb);

		p.initialize();
		while (1) {
			childs.back()->send("ready");
			std::string token;
			std::string nbr;
			std::istringstream iss(childs.back()->receive());
			std::getline(iss, token, ' ');
			std::getline(iss, nbr, ' ');
			Task *t = new Task(static_cast<Plazza::Information>(std::stoi(nbr)), token);
			p.addTask(t);
		}
		p.destroy();
	}
}

void	Dispatch::Algo(std::list <std::pair<std::list<std::string>, int>> cmd)
{
	std::list<std::pair<std::list<std::string>, int>>::const_iterator it;
	std::list<std::string>::const_iterator it2;

	if (cur_idx >= childs.size())
		cur_idx = 0;
	for (it = cmd.begin(); it != cmd.end(); ++it)
	{
		for (it2 = it->first.begin(); it2 != it->first.end(); ++it2)
		{
			if (childs.empty()) {
				launchFork();
				childs.back()->receive();
				childs.back()->send(*it2 + " " + std::to_string(it->second));
			}
			else if (cmd.size() > ((_threads_nb * 2) * childs.size())) {
				launchFork();
				childs.back()->receive();
				childs.back()->send(*it2 + " " + std::to_string(it->second));
			}
			else {
				childs[cur_idx]->receive();
				childs[cur_idx]->send(*it2 + " " + std::to_string(it->second));
			}
			cur_idx++;
			if (cur_idx >= childs.size())
				cur_idx = 0;
		}
	}
}

void	Dispatch::clearPipes()
{
	for (unsigned int i = 1; i < childs.size() + 1; i++) {
		remove(std::to_string(i).c_str());
	}
}
