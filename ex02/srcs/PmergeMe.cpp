/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anouri <anouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:19:02 by anouri            #+#    #+#             */
/*   Updated: 2024/05/27 20:20:59 by anouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &src): _vect(src.getVect()), _lst(src.getList())
{}
PmergeMe & PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        _vect = rhs.getVect();
        _lst = rhs.getList();
    }
    return *this;
}
void PmergeMe::checkArgs(int ac, char *av[])
{
    int i = 1;
    std::string arg;
    long int input;
    while(i < ac)
    {
        arg = av[i];
        for(size_t j = 0; j < arg.size(); j++)
        {
            if(!isdigit(arg[j]))
                throw(std::runtime_error("ERROR: input must be a positive integer"));
        }
        input = atol(av[i]);
        if (input < 0 || input > std::numeric_limits<int>::max())
            throw(std::runtime_error("ERROR: input must be a positive integer "));
        i++;
    }   
}

void PmergeMe::setVector(int ac, char *av[])
{   
    for(int i = 1; i < ac; i++)
        _vect.push_back(atoi(av[i]));  
}

void PmergeMe::setList(int ac, char *av[])
{
    for(int i = 0; i < ac; i++)
        _lst.push_back(atoi(av[i]));
}

std::vector<int> PmergeMe::getVect() const
{
    return(_vect);
}

std::list<int> PmergeMe::getList() const
{
    return(_lst);
}

void printVector(std::vector<int> v)
{
    for(size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

/****************************************************************************************************/
void    PmergeMe::mergeInsertSort(int ac, char *av[])
{
    checkArgs(ac, av);
    setVector(ac, av);
    int last;
    bool odd = false;
    clock_t vecTime;
    clock_t listTime;

    std::cout << "Before: ";
    printVector(_vect);
    
    if (_vect.size() % 2 == 1)
    {
        odd = 1;
        last = _vect[_vect.size() - 1];
        _vect.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    std::list<std::pair<int, int> > lstPairs;
    
    for(size_t i = 0; i < _vect.size(); i +=2)
    {
        pairs.push_back(std::make_pair(_vect[i], _vect[i + 1]));
        lstPairs.push_back(std::make_pair(_vect[i], _vect[i + 1]));
    }
    /************vector***************/
    sortPairs(pairs);
    recSortGreater(pairs);
    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    for(size_t i = 0 ; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }
    if (odd)
        pendingChain.push_back(last);
    InsertPendInMain(mainChain, pendingChain);
    vecTime = clock();
    std::cout << "After: ";
    printVector(this->getVect());
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << ((float)vecTime)/CLOCKS_PER_SEC << " seconds" << std::endl;
    /************list***************/
    sortPairsLst(lstPairs);
    recSortGreaterLst(lstPairs);
    std::list<int> mainChainLst;
    std::list<int> pendingChainLst;
    for (std::list<std::pair<int, int> >::iterator it = lstPairs.begin(); it != lstPairs.end(); ++it)
   {
        mainChainLst.push_back(it->first);
        pendingChainLst.push_back(it->second);
    }
    if (odd)
        pendingChainLst.push_back(last);
    InsertPendInMainLst(mainChainLst, pendingChainLst);
    listTime = clock();
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : " << ((float)listTime)/CLOCKS_PER_SEC << " seconds" << std::endl;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &pairs)
{
    for(size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

void PmergeMe::recSortGreater(std::vector<std::pair<int, int> > &pairs)
{
    if (pairs.size() <= 1)
        return;
    size_t mid = pairs.size() / 2;
    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    recSortGreater(left);
    recSortGreater(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) 
    {
        if (left[i].first < right[j].first)
            pairs[k++] = left[i++];
        else
            pairs[k++] = right[j++];
    }
    while (i < left.size())
        pairs[k++] = left[i++];
    while (j < right.size())
        pairs[k++] = right[j++];
}


size_t PmergeMe::doJacobstahl(int indexn_1, int indexn)
{
    return(indexn + 2*indexn_1);
}

size_t PmergeMe::findInsertionIndex(std::vector<int> v, int x)
{
    size_t l = -1;
    size_t r = v.size();
    while (l < r-1)
    {
        int h = (l+r) / 2;
        if(v[h] < x)
            l = h;
        else
            r = h;
    }
    return r;
}

void    PmergeMe::InsertPendInMain(std::vector<int> &mainChain, std::vector<int> pendingChain)
{
    size_t indextoInsert;
    size_t insertionIndex;
    size_t indexn_1 = 0;
    size_t indexn = 1;
    mainChain.insert(mainChain.begin(), 1, pendingChain[0]);
    insertionIndex = findInsertionIndex(mainChain, pendingChain[1]);
    mainChain.insert(mainChain.begin() + insertionIndex, pendingChain[1]);
    for(size_t i = 0; i < pendingChain.size(); i++)
    {
        indextoInsert = doJacobstahl(indexn_1, indexn);
        if (indextoInsert >= pendingChain.size())
        {
            indextoInsert = pendingChain.size() - 1;
        }
        for (size_t j = indextoInsert ; j > indexn ; j--)
        {
            insertionIndex = findInsertionIndex(mainChain, pendingChain[j]);
            mainChain.insert(mainChain.begin() + insertionIndex, pendingChain[j]);
        }
        indexn_1 = indexn;
        indexn = indextoInsert;
    }
    _vect = mainChain;
}

void PmergeMe::sortPairsLst(std::list<std::pair<int, int> > &pairs)
{
   for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
   {
        if (it->first < it->second) {
            std::swap(it->first, it->second);
        }
    }
}

void PmergeMe::recSortGreaterLst(std::list<std::pair<int, int> > &pairs)
{
   if (pairs.size() <= 1)
        return;

    std::list<std::pair<int, int> > left, right;
    std::list<std::pair<int, int> >::iterator it = pairs.begin();

    for (size_t i = 0; i < pairs.size() / 2; ++i)
        left.push_back(*it++);
    while (it != pairs.end())
        right.push_back(*it++);

    recSortGreaterLst(left);
    recSortGreaterLst(right);
    
    pairs.clear();
    std::list<std::pair<int, int> >::iterator itLeft = left.begin();
    std::list<std::pair<int, int> >::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (itLeft->first < itRight->first)
            pairs.push_back(*itLeft++);
        else
            pairs.push_back(*itRight++);
    }

    while (itLeft != left.end())
        pairs.push_back(*itLeft++);

    while (itRight != right.end())
        pairs.push_back(*itRight++);
}

std::list<int>::iterator PmergeMe::findInsertionIndexLst(std::list<int> &lst, int x) 
{
    std::list<int>::iterator l = lst.begin();
    std::list<int>::iterator r = lst.end();
    while (l != r) {
        std::list<int>::iterator m = l;
        std::advance(m, std::distance(l, r) / 2);
        if (*m < x)
            l = ++m;
        else
            r = m;
    }
    return r;
}


void PmergeMe::InsertPendInMainLst(std::list<int> &mainChain, std::list<int> &pendingChain)
{
    size_t indextoInsert;
    std::list<int>::iterator insertionIndex;
    size_t indexn_1 = 0;
    size_t indexn = 1;

    mainChain.push_front(pendingChain.front());
    std::list<int>::iterator itPending = pendingChain.begin();
    std::advance(itPending, 1);
    insertionIndex = findInsertionIndexLst(mainChain, *itPending);
    mainChain.insert(insertionIndex, *itPending);
    
    for (size_t i = 1; i < pendingChain.size(); ++i, ++itPending)
    {
        indextoInsert = doJacobstahl(indexn_1, indexn);
        if (indextoInsert >= pendingChain.size()) 
        {
            indextoInsert = pendingChain.size() - 1;
        }

        std::list<int>::iterator itInsert = pendingChain.begin();
        std::advance(itInsert, indextoInsert);
        std::list<int>::iterator prevInsert = pendingChain.begin();
        std::advance(prevInsert, indexn);
        while (itInsert != prevInsert)
        {
            insertionIndex =  findInsertionIndexLst(mainChain, *itInsert);
            mainChain.insert(insertionIndex, *itInsert);
            --itInsert;
        }

        indexn_1 = indexn;
        indexn = indextoInsert;
    }
    _lst = mainChain;
}

