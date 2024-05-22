

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <deque>
#include <iterator>

class PmergeMe
{
    private:
        std::vector<int> _vect;
        std::deque<int> _deq;
    public:
        PmergeMe(void);
        // PmergeMe(const PmergeMe &src);
        // PmergeMe & operator=(const PmergeMe &rhs);
        ~PmergeMe();

        void checkArgs(int ac, char *av[]);

        //setters
        void setVector(int ac, char *av[]);
        void setDeque(int ac, char *av[]);
        //getters
        std::vector<int> getVect();
        std::deque<int> getDeq();

        //merge and sort
        void mergeAndSort(std::vector<int> &v);
        void  merge(std::vector<int> left, std::vector<int> right);

};



#endif