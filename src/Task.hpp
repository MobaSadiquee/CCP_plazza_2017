//
// EPITECH PROJECT, 2018
// Task.hpp
// File description:
// Task header for the plazza
//

#include "Core.hpp"
#include "Mutex.hpp"

class Task
{
public:
	Task(Plazza::Information info, const std::string &filename);
	~Task();

	void run();

private:
	Mutex	mutex;
	Plazza::Information _type;
	std::string	_filename;
};
