/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:18:26 by anouri            #+#    #+#             */
/*   Updated: 2024/05/27 20:15:38 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <list>
#include <time.h>
#include <iterator>

class PmergeMe
{
    private:
        std::vector<int> _vect;
        std::list<int> _lst;

    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        PmergeMe & operator=(const PmergeMe &rhs);
        ~PmergeMe();

        void checkArgs(int ac, char *av[]);

        //setters
        void setVector(int ac, char *av[]);
        void setList(int ac, char *av[]);
        //getters
        std::vector<int> getVect() const;
        std::list<int> getList() const;

        /*********************************************/
        void    mergeInsertSort(int ac, char *av[]);
        void    sortPairs(std::vector<std::pair<int, int> > &pairs);
        void    recSortGreater(std::vector<std::pair<int, int> > &pairs);
        void    InsertPendInMain(std::vector<int> &mainChain, std::vector<int> pendingChain);
        
        size_t     doJacobstahl(int indexn_1, int indexn);
        size_t     findInsertionIndex(std::vector<int> v, int x);

        void    sortPairsLst(std::list<std::pair<int, int> > &pairs);
        void    recSortGreaterLst(std::list<std::pair<int, int> > &pairs);
        void    InsertPendInMainLst(std::list<int> &mainChain, std::list<int> &pendingChain);
        std::list<int>::iterator findInsertionIndexLst(std::list<int> &lst, int x);
        
};


#endif