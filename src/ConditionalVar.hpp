//
// EPITECH PROJECT, 2018
// ConditionalVar.hpp
// File description:
// Conditional variable for plazza
//

#include <pthread.h>

class ConditionalVar
{
public:
	ConditionalVar();
	~ConditionalVar();

	void	wait(pthread_mutex_t *mutex);
	void	broadcast();
	void	signal();

private:
	pthread_cond_t cond;
};
