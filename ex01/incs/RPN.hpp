
#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <exception>
#include <stdlib.h>

class RPN
{
    private:
        std::stack<int> _mem;
        RPN(void);
    public:
        RPN(const RPN &src);
        RPN & operator=(const RPN &rhs);
        RPN(std::string expression);
        ~RPN();

        /*parsing*/
        void parseExpression(std::string expression);
        void calculate(std::string expression);
        int doRPN(int a, int b, char op);
};





#endif