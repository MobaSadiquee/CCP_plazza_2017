//
// EPITECH PROJECT, 2018
// cpp_plaza
// File description:
// the class function for pipe communication
//

#include <string>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "Pipe.hpp"

void	Pipe::create(std::string channel_name)
{
	int	i;

	i = mkfifo(channel_name.c_str(),  S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
	if (i != 0){
		std::cerr <<"Failed to create com pipe" << std::endl;
		exit(84);
	}
	this->ChannelName = channel_name;
}

void	Pipe::send(std::string	mess)
{
	int	fd;
	unsigned int	er = 0;
	int	num;
	char	*message;

	fd = open(this->ChannelName.c_str(), O_WRONLY);
	message = strdup(mess.c_str());
	if (fd == -1){
		std::cerr <<"Failed to open channel: "
			  << this->ChannelName.c_str() << std::endl;
		exit(84);
	}
	while (er < mess.size()){
		num = write(fd, message + er, mess.size() + 1 - er);
		if (num < 0)
			break ;
		er += num;
	}
	close(fd);
}

std::string		Pipe::receive()
{
	int		fd;
        int		er = 0;
	char		temp[25];
	std::string	ret;
	int		num;

        fd = open(this->ChannelName.c_str(), O_RDONLY);
	if (fd == -1){
		std::cerr <<"Failed to open channel: "
			  << this->ChannelName.c_str() << std::endl;
                exit(84);
        }
	while (er < 25){
		num = read(fd, temp + er, 25 - er);
		if (num <= 0)
			break ;
		er += num;
	}
	close(fd);
	ret = temp;
	return (ret);
}

std::string	Pipe::getChannelName()
{
	return(this->ChannelName);
}
