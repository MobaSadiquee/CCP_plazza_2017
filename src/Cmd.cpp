//
// EPITECH PROJECT, 2018
// parser_func.cpp
// File description:
// parser function for the plazza project
//

#include "my.hpp"
#include "Cmd.hpp"
#include <unistd.h>

Cmd::Cmd()
{
	this->_exit = false;
	this->_help = false;
}

Cmd::~Cmd()
{}

bool	Cmd::getExit() const
{
	return (this->_exit);
}

bool	Cmd::getHelp() const
{
	return (this->_help);
}

std::list <std::pair<std::list<std::string>, int> >  Cmd::getCmd() const
{
	return (this->_exec);
}

bool	Cmd::separate_list(std::string const cmd)
{
	char const	*wordtab;
	std::string	str;

	str = epur_str(cmd);
	if (check_semi(str) == KO)
		return (false);
	if ((wordtab = strtok((char*)str.c_str(), ";")) == NULL)
		return (false);
	while (wordtab != 0) {
		_list.push_back(std::string(wordtab));
		wordtab = strtok(NULL, ";");
	}
	return (true);
}

bool	Cmd::exec_other()
{
	std::list<std::pair<std::list<std::string>, int> >::const_iterator i;
	std::list<std::string>::const_iterator j;

	i = _exec.begin();
	while (i != _exec.end()) {
		j = i->first.begin();
		while(j != i->first.end()) {
			if (*j == "help") {
				print_help();
				this->_help = true;
			}
			else if (*j == "exit")
				this->_exit = true;
			j++;
		}
		i++;
	}
	return (true);
}

bool	Cmd::check_copy(std::list<std::string> tmp)
{
	std::list<std::string>		copy;
	std::list<std::string>::const_iterator	i;

	i = tmp.begin();
	while (i != tmp.end()) {
		copy.push_back(*i);
		i++;
	}
	copy.remove(copy.back());
	if (copy.empty() != false) {
		std::cerr << RED << "plazza: Wrong command." << BLANK << std::endl;
		return (false);
	}
	check_file(&copy);
	if (copy.empty() != false) {
		std::cerr << RED << "plazza: File(s) not found" << BLANK << std::endl;
		return (false);
	}
	_listtmp = copy;
	return (true);
}

bool    Cmd::set_type(std::list<std::string> cmd, std::string type)
{
	const char *str;

	str = type.c_str();
	if (strncmp(str, "PHONE_NUMBER", 12) == 0) {
		_exec.push_back(make_pair(cmd, 1));
		return (true);
	}
	else if (strncmp(str, "EMAIL_ADDRESS", 13) == 0) {
		_exec.push_back(make_pair(cmd, 2));
		return (true);
	}
	else if (strncmp(str, "IP_ADDRESS", 10) == 0) {
		_exec.push_back(make_pair(cmd, 3));
		return (true);
	}
	std::cout << RED << "plazza: error type." << BLANK << std::endl;
	return (false);
}

bool	Cmd::check_cmd(std::list<std::string>::const_iterator string)
{
	std::string		str;
	const char		*cmd;
	const char		*wordtab;
	std::list<std::string>	tmp;

	str = *string;
	cmd = str.c_str();
	wordtab = strtok((char*)cmd, " ");
	while (cmd && wordtab != 0) {
		tmp.push_back(std::string(wordtab));
		wordtab = strtok(NULL, " ");
	}
	if ((check_copy(tmp)) == false)
		return (false);
	if ((set_type(this->_listtmp, tmp.back())) == false)
		return (false);
	return (true);
}

int	Cmd::read_cmd()
{
	std::string		str;
	const char		*cmd;
	std::list<std::string>  tmp;
	std::list<std::string>::const_iterator	i;

	i = _list.begin();
	while (i != _list.end()) {
		str = *i;
		cmd = str.c_str();
		if (strncmp(cmd, "exit", 4) == 0 || strncmp(cmd, "help", 4) == 0) {
			tmp.push_back(cmd);
			_exec.push_back(make_pair(tmp, 0));
		}
		else {	
			if ((check_cmd(i)) == false)
				return (KO);
		}
		i++;
	}
	exec_other();
	return (OK);
}

void    Cmd::clearList()
{
	_exec.clear();
	_list.clear();
}

int     Cmd::get_cmd(std::string str)
{
	std::list<std::pair<std::list<std::string>, int>>::const_iterator it;
	std::list<std::string>::const_iterator it2;

        this->_help = false;
	if (separate_list(str) == false) {
		std::cerr << RED << "plazza: Wrong command." << BLANK << std::endl;
		return (KO);
	}
	if (read_cmd() == KO) {
		clearList();
		return (KO);
	}
	return (OK);
}
