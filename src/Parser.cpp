//
// EPITECH PROJECT, 2018
// Parser.cpp
// File description:
// Parser func for the plazza
//

#include "Parser.hpp"

Parser::Parser(Plazza::Information info, const std::string &filename) : to_parse(info), _filename(filename)
{
	
}

Parser::~Parser()
{
	
}

void	Parser::parse()
{
	std::regex	email(EMAIL_REGEX);
	std::regex	phone(PHONE_REGEX);
	std::regex	ip(IP_REGEX);

	if (to_parse == Plazza::PHONE_NUMBER)
		parsePhones(phone);
	if (to_parse == Plazza::EMAIL_ADDRESS)
		parseEmails(email);
	if (to_parse == Plazza::IP_ADDRESS)
		parseIp(ip);
}

void	Parser::parseEmails(std::regex search)
{
	std::string	line;
	std::ifstream	file(this->_filename);
	
	while (std::getline(file, line))
	{
		const std::sregex_token_iterator end;
		std::sregex_token_iterator str(line.begin(), line.end(), search) ;
		while (str != end)
		{
			this->collectedData += *str;
			str++;
		}
	}
	std::cout << this->collectedData.c_str() << std::endl;
}

void	Parser::parseIp(std::regex search)
{
	std::string     line;
	std::ifstream   file(this->_filename);

	while (std::getline(file, line))
	{
		const std::sregex_token_iterator end;
		std::sregex_token_iterator str(line.begin(), line.end(), search) ;
		while (str != end)
		{
			this->collectedData += *str;
			str++;
		}
	}
	std::cout << this->collectedData.c_str() << std::endl;
}

void	Parser::parsePhones(std::regex search)
{
	std::string     line;
	std::ifstream   file(this->_filename);

	while (std::getline(file, line))
	{
		const std::sregex_token_iterator end;
		std::sregex_token_iterator str(line.begin(), line.end(), search) ;
		while (str != end)
		{
			this->collectedData += *str;
			str++;
		}
	}
	std::cout << this->collectedData.c_str() << std::endl;
}
