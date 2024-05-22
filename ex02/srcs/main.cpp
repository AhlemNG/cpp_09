
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
       p.checkArgs(ac, av);
       p.setVector(ac, av);
       std::vector<int> v = p.getVect();
       std::cout<< "********vector\n";
       for(size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    p.mergeAndInsert(v, p.inf, p.sup);
    std::vector<int> v1 = p.getVect();
    // std::cout<< "********vector\n";
    // for(size_t i = 0; i < v1.size(); i++)
    //     std::cout << v1[i] << std::endl;
       /*********/

    //    p.setDeque(ac, av);
    //    std::deque<int> d = p.getDeq();
    //    std::cout<< "********deque\n";
    //    for(size_t i = 0; i < d.size(); i++)
    //     std::cout << d[i] << std::endl;

        /*********/
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}