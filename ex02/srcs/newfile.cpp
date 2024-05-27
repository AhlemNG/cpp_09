
#include "../incs/PmergeMe.hpp"

/*supposed to have one function 
void MergeInsertSort()
{
    bla bla bla 
}*/
    
void PmergeMe::mergeAndInsert(std::vector<int> v, std::vector<std::vector<int> > &matrix)
{
    std::vector<int> left;
    std::vector<int> right;


    bool odd = false;
    int last;
    // int nbPairs = 0;
    //1.Group the elements of X into [n/2] pairs of elements, (leave one unpaired element if odd size)
    //2.Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.

    if (v.size() == 2)
    {
        // sortPair(v);    
        // inf.push_back(v[0]);
        // sup.push_back(v[1]);
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
   
    if (left.size() == 2 && right.size() == 2)
    {
        sortPair(left);
        sortPair(right);
        sortQuadruple(right, left, matrix);
        std::cout<< "********matrix\n";
        for(size_t i = 0; i < matrix.size(); i++)
            std::cout << matrix[i][0] << " " << matrix[i][1] << std::endl;
    }

    mergeAndInsert(left, matrix);
    mergeAndInsert(right, matrix);


    /****************printing*****************/
    // std::cout<< "********inf\n";
    // for(size_t i = 0; i < inf.size(); i++)
    //     std::cout << inf[i] << std::endl;
    // std::cout<< "********sup\n";
    // for(size_t i = 0; i < sup.size(); i++)
    //     std::cout << sup[i] << std::endl;
    /****************printing*****************/
   //3.Recusrsively sort the [n/2] larger elements from each pair, creating a sorted sequence S 
   // of [n/2] of the input elements, in ascending order
    // recSortLarger(inf, sup);

    if (odd)
    {
        std::cout << "odd is here dot not forget :D" << std::endl;
        inf.push_back(last);
    } 
}

void PmergeMe::sortPair(std::vector<int> &vec)
{
    if (vec[0] < vec[1])
        std::swap(vec[1], vec[0]);
}

void PmergeMe::sortQuadruple(std::vector<int>left, std::vector<int> right, std::vector<std::vector<int> > &matrix)
{
    // if (matrix.size() == 2)
    //     return;
    if (!left.empty() && !right.empty())
    {
        if (left[0] > right[0])
        {
            matrix.push_back(right);
            matrix.push_back(left);

        }
        else
        {
            matrix.push_back(left);
            matrix.push_back(right);
        }
    }
}


/****************************************************************************************************/
void    PmergeMe::mergeInsertSort(std::vector<int> v)
{
    int last;
    bool odd = false;

    if (v.size() % 2 == 1)
    {
        odd = 1;
        last = v[v.size() - 1];
        v.pop_back();
    }
    //1- create an array of pairs
    std::vector<std::pair<int, int> > pairs;
    for(size_t i = 0; i < v.size(); i +=2)
        pairs.push_back(std::make_pair(v[i], v[i + 1]));
    //sort pairs
    sortPairs(pairs);
    std::cout<< "********sorting pairs*****\n";
    for(size_t i = 0; i < pairs.size(); i++)
        std::cout << "pairs[i]: [" << pairs[i].first << ", " << pairs[i].second << "]\n";
    //2- sort by greater
    recSortGreater(pairs);
     std::cout<< "********sorting pairs by greater*****\n";
    for(size_t i = 0; i < pairs.size(); i++)
        std::cout << "pairs[i]: [" << pairs[i].first << ", " << pairs[i].second << "]\n";
    //create a array and b array
    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    for(size_t i = 0 ; i < pairs.size(); i++)
    {
        mainChain.push_back(pairs[i].first);
        pendingChain.push_back(pairs[i].second);
    }
    if (odd)
        pendingChain.push_back(last);
    std::cout << "pending chain\n";
    for(size_t k = 0 ; k < pendingChain.size(); k++)
    {
        std::cout << pendingChain[k] << std::endl;
    }
    InsertPendInMain(mainChain, pendingChain);
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

    // Merge sorted halves
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) 
    {
        if (left[i].first < right[j].first)
            pairs[k++] = left[i++];
        else
            pairs[k++] = right[j++];
    }
    //eventual last element
    while (i < left.size())
        pairs[k++] = left[i++];
    while (j < right.size())
        pairs[k++] = right[j++];
}

int PmergeMe::doJacobstahl(int indexn_1, int indexn)
{
    return(indexn + 2*indexn_1);
}

int PmergeMe::findInsertionIndex(std::vector<int> v, int x)
{
    int l = -1;
    int r = v.size();
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
     std::cout << "main chain\n";
        for(size_t k = 0 ; k < mainChain.size(); k++)
        {
            std::cout << mainChain[k] << std::endl;
        }
    for(size_t i = 0; i < pendingChain.size(); i++)
    {
        indextoInsert = doJacobstahl(indexn_1, indexn);
        if (indextoInsert > pendingChain.size())
            indextoInsert = indexn + 1;
        if (indextoInsert >= pendingChain.size())
        {
            indextoInsert = pendingChain.size() - 1;
        }
        for (size_t j = indextoInsert ; j > indexn && j < pendingChain.size(); j--)
        {
            std::cout << "index to insert = " << j << std::endl;
            std::cout << "element to insert = " << pendingChain[j] << std::endl;

            insertionIndex = findInsertionIndex(mainChain, pendingChain[j]);
            mainChain.insert(mainChain.begin() + insertionIndex, pendingChain[j]);
        }
        indexn_1 = indexn;
        indexn = indextoInsert;
    }
        std::cout << "main chain\n";
        for(size_t k = 0 ; k < mainChain.size(); k++)
        {
            std::cout << mainChain[k] << std::endl;
        }
}


