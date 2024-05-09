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