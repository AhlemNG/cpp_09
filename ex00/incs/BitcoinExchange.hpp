/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:31 by anouri            #+#    #+#             */
/*   Updated: 2024/05/11 16:19:56 by anouri           ###   ########.fr       */
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

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dataBase;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange & operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void ParseCsvFile(std::ifstream & dataFile); // c'est necessaire ? 
        void ParseInputFile(std::ifstream & inputFile);
        void getExchange(std::string key, std::string value); //cela va donner le resultat demande 

        void checkLineCsv(std::string line); //ligne par ligne 
        void checkLineInput(std::string line); //ligne par ligne 
        void checkDate(const std::string &date); //date
};

#endif