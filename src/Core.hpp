//
// EPITECH PROJECT, 2018
// plazza.hpp
// File description:
// main header for plazza project
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include "my.hpp"
#include "Cmd.hpp"

namespace	Plazza
{
	enum Information
	{
		PHONE_NUMBER = 1,
		EMAIL_ADDRESS = 2,
		IP_ADDRESS = 3
	};
	class Core
	{
	public:
		Core();
		~Core();
		void	prompt(Cmd Cmd, int i);
		int	initPlazza(int nbThreads);
	private:
		int		_nbThreads;
		std::string	_cmd;
	};
}

#endif /* CORE_HPP_ */
