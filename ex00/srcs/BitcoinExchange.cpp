/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:36 by anouri            #+#    #+#             */
/*   Updated: 2024/05/28 17:35:44 by anouri           ###   ########.fr       */
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


void BitcoinExchange::ParseCsvFile(std::ifstream & dataFile)
{
    std::string line;
    std::string firstLine;

    if (!getline(dataFile, firstLine))
        throw(std:: runtime_error(EMPTY_FILE));
    if (!getline(dataFile, line))
        throw(std:: runtime_error(NO_DATA));
    else 
        checkLineCsv(line);
    while (getline(dataFile, line))
    {
        checkLineCsv(line);
    }
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::checkLineCsv(std::string line)
{
    std::string date;
    int hasDot = 0;
    for(size_t i = 0; i < line.size(); i++)
    {
        if ((i == 4 || i == 7) && line[i] == '-')
            ;//nothing to do here
        else if (i == 10 && line[i] == ',')
        {
            date = line.substr(0, 10);
            checkDate(date);
        }
        if (i > 10)
        {
            if (line[i] == '.' && !hasDot)
                hasDot = 1;
            else if (!isdigit(line[i]))
                throw(std:: runtime_error(NOT_VALID + /*" => " +*/ line));
            else if (i == line.size() - 1)
            _dataBase[date] = atof(line.substr(11).c_str());
        }

    }
}

void BitcoinExchange::checkDate(const std::string &date)
{
    int y, m, d;

    y = atoi(date.substr(0, 4).c_str());
    m = atoi(date.substr(5, 2).c_str());
    d = atoi(date.substr(8, 2).c_str());

    if (y > 9999 || y < 1000) //yyyy
        throw(std:: runtime_error("Error: bad input => " + date));
    if (m > 12 || m < 1)    
        throw(std:: runtime_error("Error: bad input => " + date));
    
    int maxDays = 31;
    if (m == 2)
        maxDays = isLeapYear(y) ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        maxDays = 30;
    if (d < 1 || d > maxDays)
        throw std:: runtime_error("Error: bad input => " + date);
}
 
void BitcoinExchange::ParseInputFile(std::ifstream & inputFile)
{
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
         throw(std:: runtime_error(BAD_FORMAT));
    while(std::getline(inputFile, line))
    {
        try
        {
            checkLineInput(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void BitcoinExchange::checkLineInput(std::string line)
{
    std::string date;
    int hasDot = 0;
    if (line.size() < 14)
		throw std::runtime_error("Error: bad input => " + line);
    for (size_t i = 0; i < line.size(); i++)
	{
		if ((i == 4 || i == 7) && line[i] == '-')
			;
		else if ((i == 10 || i == 12) && line[i] == ' ')
			;
		else if (i == 11 && line[i] == '|')
		{
			date = line.substr(0, i - 1);
			checkDate(date);
		}
        else if (i > 10 && line[i] == '.' && !hasDot)
			hasDot = 1;
		else if (line[i] != '-' && !isdigit(line[i]))
			throw std::runtime_error("Error: bad input => " + line);
		else if (i == line.size() - 1)
        {
            std::string value = line.substr(13, line.size() - 11); 
			getExchange(date, value);
        }
	}
}

bool  isAnteriorDate(std::string date)
{
    (void) date;
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    
    now->tm_year += 1900;
    std::tm tm = {};
    std::istringstream ss(date);
    char dash1, dash2;
    ss >> tm.tm_year >> dash1 >> tm.tm_mon >> dash2 >> tm.tm_mday;

    if (ss.fail() || dash1 != '-' || dash2 != '-') {
        throw std::runtime_error("Failed to parse date string");
    }
    tm.tm_mon -= 1;
    if (now->tm_year < tm.tm_year)
    {
        return (true);
    }
    else if (now->tm_year == tm.tm_year && now->tm_mon < tm.tm_mon)
        return (true);
    else if (now->tm_year == tm.tm_year && now->tm_mon == tm.tm_mon && now->tm_mday < tm.tm_mday)
    {
        return (true);
    }
    return (false);
}

bool BitcoinExchange::isPosteriorDate(std::string date)
{
    if (strncmp(date.c_str(), _dataBase.begin()->first.c_str(), date.size()) < 0)
        return (true);
    return (false);
}




void BitcoinExchange::getExchange(std::string key, std::string value)
{
    if(isAnteriorDate(key))
        throw std::runtime_error("Error: date is in the future : => " + key);
    if (isPosteriorDate(key))
        throw std::runtime_error("Error: date is in anterior to the first date in dataBase : => " + key);
    double val = atof(value.c_str());
    if (val > 1000)
        throw std::runtime_error("Error: too large a number.");
    else if (val < 0)
    {
        throw std::runtime_error("Error: not a positive number.");
    }

    if (_dataBase.empty()) {
        throw std::runtime_error("Error: _dataBase is empty.");
    }
    
    std::map<std::string, double>::iterator it = _dataBase.find(key);
    if (it != _dataBase.end())
        std::cout << key << " => " << val << " = " << (val * it->second) << std::endl;
    else
    {
        it = _dataBase.lower_bound(key);
        if (it != _dataBase.begin())
            --it;
        std::cout << key << " => " << val << " = " << (val * it->second) << std::endl;
    }
}
