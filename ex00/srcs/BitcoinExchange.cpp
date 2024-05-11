/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:36 by anouri            #+#    #+#             */
/*   Updated: 2024/05/11 16:33:17 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src):_dataBase(src._dataBase){}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
        _dataBase = rhs._dataBase;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::ParseInputFile(std::ifstream & inputFile)
{
    std::string line ;
    // char *date;
    // char *value;
    std::getline(inputFile, line);
    // std::cout << line << std::endl;
    if (line != "date | value")
        std::cout << "error\n";
    while(std::getline(inputFile, line))
    {
        // std::cout << line << std::endl;
        try
        {
            checkLine(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void BitcoinExchange::checkLine(std::string line)
{
    // if (line.size() < 14)
    //     throw std::runtime_error(BAD_INPUT);
    // if (line[11] != '|')
    //     throw std::runtime_error(BAD_INPUT);
    /*parse date here*/
    unsigned long i = 0;
   
}