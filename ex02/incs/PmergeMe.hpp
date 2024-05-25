

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


        void mergeAndInsert(std::vector<int> v, std::vector<int> &inf, std::vector<int> &sup);
        void sortPair(std::vector<int> &vec);
        void recSortLarger(std::vector<int> &inf, std::vector<int>&sup);
        //not best practice!
        std::vector<int> inf;
        std::vector<int> sup;
        void mergeAndInsert(std::vector<int> v, std::vector<std::vector<int> > &matrix);
        void sortQuadruple(std::vector<int>left, std::vector<int> right, std::vector<std::vector<int> > &matrix);
        std::vector<std::vector<int> > matrix;
        /*********************************************/
        void    mergeInsertSort(std::vector<int> v);
        void    sortPairs(std::vector<std::pair<int, int> > &pairs);
        void    recSortGreater(std::vector<std::pair<int, int> > &pairs);
        void    InsertPendInMain(std::vector<int> &mainChain, std::vector<int> pendingChain);
        
        int     doJacobstahl(int indexn_1, int indexn);
        int     findInsertionIndex(std::vector<int> v, int x);

};



#endif