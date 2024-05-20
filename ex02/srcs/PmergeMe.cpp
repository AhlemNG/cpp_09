#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe()
{
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
            // std::cout << arg[j] << std::endl;
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
    for(int i = 0; i < ac; i++)
        _vect.push_back(atoi(av[i]));
}

void PmergeMe::setDeque(int ac, char *av[])
{
    for(int i = 0; i < ac; i++)
        _deq.push_back(atoi(av[i]));
}

std::vector<int> PmergeMe::getVect()
{
    return(_vect);
}

std::deque<int> PmergeMe::getDeq()
{
    return(_deq);
}

void PmergeMe::mergeAndSort(std::vector<int> v)
{
    std::vector<int> left;
    std::vector<int> right;

    //cut until size == 1

    if (v.size() == 1)
        return;
    for (size_t i= 0; i < v.size()/2; i++)
        left.push_back(v[i]);
   std::cout<< "********left\n";
       for(size_t i = 0; i < left.size(); i++)
        std::cout << v[i] << std::endl;
    for(size_t i = v.size()/2; i < v.size(); i++)
        right.push_back(v[i]);
       std::cout<< "********right\n";
       for(size_t i = 0; i < right.size(); i++)
        std::cout << right[i] << std::endl;
    mergeAndSort(left);
    mergeAndSort(right);

    _vect = sort(right, left);
    std::cout<< "********_vect\n";
    for(size_t i = 0; i < right.size(); i++)
        std::cout << right[i] << std::endl;
}

std::vector<int> PmergeMe::sort(std::vector<int> left, std::vector<int> right)
{
    if(right.empty())
        return(left); 
    for (std::vector<int>::iterator it = left.begin(); it < left.end(); it++)
    {
        if(*it> right[0])
            left.insert(it, 1, right[0]);
    }
    return (what?);
}
