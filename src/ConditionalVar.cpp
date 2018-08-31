//
// EPITECH PROJECT, 2018
// ConditionalVar.cpp
// File description:
// Conditional variable for plazza
//

#include "ConditionalVar.hpp"

ConditionalVar::ConditionalVar()
{
	pthread_cond_init(&cond, NULL);
}

ConditionalVar::~ConditionalVar()
{
	pthread_cond_destroy(&cond);
}

void	ConditionalVar::wait(pthread_mutex_t *mutex)
{
	pthread_cond_wait(&cond, mutex);
}

void	ConditionalVar::broadcast()
{
	pthread_cond_broadcast(&cond);
}

void	ConditionalVar::signal()
{
	pthread_cond_signal(&cond);
}
