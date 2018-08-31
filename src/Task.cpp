//
// EPITECH PROJECT, 2018
// Task.cpp
// File description:
// Task func for the plazza
//

#include <iostream>
#include "Parser.hpp"
#include "Task.hpp"

Task::Task(Plazza::Information info, const std::string &filename) : _type(info), _filename(filename)
{
	
}

void	Task::run()
{
	mutex.lock();
	Parser p(_type, _filename);
	p.parse();
	mutex.unlock();
}

Task::~Task()
{

}
