
#include <../incs/RPN.hpp>

int main(int ac, char *av[])
{
    std::string expression;
    try{
        if (ac != 2)
            throw(std::runtime_error("ERROR: wrong arguments number"));
        expression = av[1];
        RPN calculator(expression);
        // calculator.parsExpression(static_cast<std::string>(av[1]));
        // std::cout << av[1] << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}