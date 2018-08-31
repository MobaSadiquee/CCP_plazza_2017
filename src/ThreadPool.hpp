//
// EPITECH PROJECT, 2018
// ThreadPool.hpp
// File description:
// ThreadPool header for the plazza
//

#include <vector>
#include <deque>
#include <pthread.h>
#include "Task.hpp"
#include "ConditionalVar.hpp"

class ThreadPool
{
public:
	ThreadPool(int p_size);
	~ThreadPool();

	void	initialize();
	void	destroy();
	void	execute();
	void	addTask(Task *task);

private:
	enum ThreadsState
	{
		STARTED,
		STOPPED
	};
	
	ConditionalVar	cond_var;
	Mutex		mutex;
	std::vector<pthread_t>	threads;
	std::deque<Task*>	tasks;
	int	state;
	int	pool_size;
};
