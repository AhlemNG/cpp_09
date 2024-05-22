
#include "../incs/PmergeMe.hpp"


void PmergeMe::mergeAndInsert(std::vector<int> v, std::vector<int> &inf, std::vector<int>&sup)
{
    std::vector<int> left;
    std::vector<int> right;


    bool odd = false;
    int last;
    //1.Group the elements of X into [n/2] pairs of elements, (leave one unpaired element if odd size)
    //2.Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.

    if (v.size() == 2)
    {
        sortPair(v);
        inf.push_back(v[0]);
        sup.push_back(v[1]);
        /****************printing*****************/
        std::cout<< "********vect\n";
        for(size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << std::endl;
        /****************printing*****************/
        return;
    }
    if (v.size() % 2 == 1)
    {
        odd = 1;
        last = v[v.size() - 1];
    }
    if (odd)
    {
        for(size_t i = 0; i < v.size() - 1; i++)
        {
            if (i < v.size() / 2)
                left.push_back(v[i]);
            else
                right.push_back(v[i]);
        }
    }
    else
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            if (i < v.size() / 2)
                left.push_back(v[i]);
            else
                right.push_back(v[i]);
        }
    }
    // if (v.size() > 2)
    // {
        mergeAndInsert(left, inf, sup);
        mergeAndInsert(right, inf, sup);
    // }
   
    /****************printing*****************/
    std::cout<< "********inf\n";
    for(size_t i = 0; i < inf.size(); i++)
        std::cout << inf[i] << std::endl;
    std::cout<< "********sup\n";
    for(size_t i = 0; i < sup.size(); i++)
        std::cout << sup[i] << std::endl;
    /****************printing*****************/
   //3.Recusrsively sort the [n/2] larger elements from each pair, creating a sorted sequence S 
   // of [n/2] of the input elements, in ascending order
    recSortLarger(inf, sup);

    if (odd)
    {
        std::cout << "odd is here dot not forget :D" << std::endl;
        inf.push_back(last);
    } 
}

void PmergeMe::sortPair(std::vector<int> &vec)
{
    if (vec[0] > vec[1])
        std::swap(vec[1], vec[0]);
}


void PmergeMe::recSortLarger(std::vector<int> &inf, std::vector<int>&sup)
{
    if ()
    {

    }
}