/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:31 by anouri            #+#    #+#             */
/*   Updated: 2024/05/28 17:21:43 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <map>
#include <iostream>
#include "Colors.hpp"
#include <string>
#include <fstream>
#include <exception>
#include "define.h"
#include <cstdlib>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string.h>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _dataBase;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange & operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void ParseCsvFile(std::ifstream & dataFile);
        void ParseInputFile(std::ifstream & inputFile);
        void getExchange(std::string key, std::string value); 

        void checkLineCsv(std::string line);
        void checkLineInput(std::string line);
        void checkDate(const std::string &date);
        
        bool isPosteriorDate(std::string date);
        
};

#endif