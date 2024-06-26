/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:42:49 by anouri            #+#    #+#             */
/*   Updated: 2024/05/28 15:56:21 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/BitcoinExchange.hpp"



int main(int ac, char *av[])
{
    std::ifstream input;
    std::ifstream csv;
    try
    {
        if (ac != 2)
            throw std:: runtime_error("Error: could not open file.\n");
        input.open(av[1]);
        csv.open("data.csv");
        if (!input.is_open() || !csv.is_open())
        {
            input.close();
		    csv.close();
            std::cout << "Error: could not open file.\n";
            return(1);
        }
        BitcoinExchange B;
        B.ParseCsvFile(csv);
        B.ParseInputFile(input);
        input.close();
        csv.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return(0);
}