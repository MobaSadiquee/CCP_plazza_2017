//
// EPITECH PROJECT, 2018
// parsercmd
// File description:
// command parser header for plazza
//

#ifndef CMD_HPP_
# define CMD_HPP_

#include <list>
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include "my.hpp"

class	Cmd
{
public:
	Cmd();
	~Cmd();

	bool	separate_list(std::string const);
	bool	exec_other();
	bool	set_type(std::list<std::string> cmd, std::string type);
	bool	check_copy(std::list<std::string> tmp);
	bool	check_cmd(std::list<std::string>::const_iterator);
        int	read_cmd();
	int	get_cmd(std::string str);
	bool	getExit() const;
	bool	getHelp() const;
	void	clearList();
	std::list <std::pair<std::list<std::string>, int> >  getCmd() const;
	
	
private:
	bool		_help;
	bool		_exit;
	std::list<std::string> 		_list;
	std::list<std::string>          _listtmp;
	std::list <std::pair<std::list<std::string>, int> >	_exec;
};

#endif /* _CMD_HPP_ */
