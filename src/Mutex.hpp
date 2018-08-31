//
// EPITECH PROJECT, 2018
// Mutex.hpp
// File description:
// Mutex header for the plazza
//

#include <pthread.h>

class Mutex
{
public:
	Mutex();
	~Mutex();

	void	lock();
	void	unlock();
	pthread_mutex_t	*get();

private:
	pthread_mutex_t _lock;
	bool is_locked;
};
