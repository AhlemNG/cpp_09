
#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <map>
#include <iostream>
#include "Colors.hpp"
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dataBase;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange & operator=(const BitcoinExchange &rhs);
        ~BitcoinExchange();

        void ParseInputFile(char * fileName);
        void ParseCsvFile(); // c'est necessaire ? 
        void getExchange(); //cela va donner le resultat demande 

        void checkLine(); //ligne par ligne 
        void checkKey(); //date
        void checkValue(); //valeur
};

#endif