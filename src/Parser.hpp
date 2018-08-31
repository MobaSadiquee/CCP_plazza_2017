//
// EPITECH PROJECT, 2018
// Parser.hpp
// File description:
// Parser func for the plazza
//

#include <regex>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "Core.hpp"

#define EMAIL_REGEX "^[_a-z0-9-]+(.[_a-z0-9-]+)*@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,4})$"
#define PHONE_REGEX "(0[1-9][[:space:]]?)([[:digit:]]{2}[[:space:]]?){4}"
#define IP_REGEX "(?:(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)\\.){3}(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)"


class Parser
{
public:
	Parser(Plazza::Information info, const std::string &filename);
	~Parser();

	void parse();

private:
	void	parseEmails(std::regex search);
	void	parseIp(std::regex search);
	void	parsePhones(std::regex search);
	
	Plazza::Information	to_parse;
	std::string		_filename;
	std::string		collectedData;
};
