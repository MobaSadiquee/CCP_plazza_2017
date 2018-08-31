//
// EPITECH PROJECT, 2018
// cpp_plaza
// File description:
// hpp file for pipe class
//

#ifndef PIPE_HPP_
# define PIPE_HPP_

class	Pipe
{
public:
	void		create(std::string channel_name);
	void		send(std::string message);
	std::string	receive();
	size_t		getLastMessageSize();
	std::string	getChannelName();
private:
	std::string	ChannelName;
	size_t		LastMessageSize = 0;
};

#endif /* PIPE_HPP */
