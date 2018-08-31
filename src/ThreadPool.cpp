//
// EPITECH PROJECT, 2018
// ThreadPool.cpp
// File description:
// ThreadPool func for the plazza
//

#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int p_size) : pool_size(p_size)
{
	
}

ThreadPool::~ThreadPool()
{
	
}

void	*handle_thread(void *arg)
{
	ThreadPool	*_this = (ThreadPool*)arg;

	_this->execute();
	return 0;
}

void	ThreadPool::initialize()
{
	state = STARTED;
	for (int i = 0; i < pool_size; i++) {
		pthread_t t;
		pthread_create(&t, NULL, handle_thread, this);
		threads.push_back(t);
	}
}

void	ThreadPool::destroy()
{
	mutex.lock();
	state = STOPPED;
	mutex.unlock();
	cond_var.broadcast();
	for (int i = 0; i < pool_size; i++) {
		pthread_join(threads[i], NULL);
		cond_var.broadcast();
	}
}

void	ThreadPool::execute()
{
	Task	*task;
	while (1) {
		mutex.lock();
		while (state != STOPPED && tasks.empty()) {
			cond_var.wait(mutex.get());
		}
		if (state == STOPPED) {
			mutex.unlock();
			pthread_exit(NULL);
		}
		task = tasks.front();
		tasks.pop_front();
		mutex.unlock();
		task->run();
		delete task;
	}
}

void	ThreadPool::addTask(Task *task)
{
	mutex.lock();
	tasks.push_back(task);
	cond_var.signal();
	mutex.unlock();
}
