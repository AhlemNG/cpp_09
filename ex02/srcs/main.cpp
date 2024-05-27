/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:18:35 by anouri            #+#    #+#             */
/*   Updated: 2024/05/27 20:12:56 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "ERROR: wrong arguments number" << std::endl;
        return (1);
    }
    try
    {
       PmergeMe p;
       p.mergeInsertSort(ac, av); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}