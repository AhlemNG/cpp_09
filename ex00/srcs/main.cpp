/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:49 by anouri            #+#    #+#             */
/*   Updated: 2024/05/11 14:59:36 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    std::ifstream input;
    std::fstream csv;
    try
    {
        if (ac != 2)
            throw std::runtime_error("Error: could not open file.\n");
        input.open(av[1]);
        csv.open("data.csv");
        if (!input.is_open() || !csv.is_open())
        {
            std::cout << "Error: could not open file.\n";
            //close peut etre les fichiers?
            return(1);
        }
        
        BitcoinExchange B;
        B.ParseInputFile(input);
        // else
        // {
        //     //input file(open it and read it ? )
        // }
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return(0);
}