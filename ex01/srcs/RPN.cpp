#include "../incs/RPN.hpp"


RPN::RPN(void){}
RPN::RPN(const RPN &src): _mem(src._mem)
{}
RPN & RPN::operator=(const RPN &rhs)
{
    if(this != &rhs)
    {
        _mem = rhs._mem;
    }
    return(*this);
}

RPN::RPN(std::string expression)
{   
    parseExpression(expression);
    calculate(expression);
}

RPN::~RPN(){}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c== '/')
        return(true);
    return(false);
}

void printStack(std::stack<int> s)
{
    while(s.size() != 0)
    {
        std::cout << s.top() << std::endl;
        s.pop();

    }
}



void RPN::parseExpression(std::string expression)
{
    if (!isdigit(expression[0]) || !isdigit(expression[2]))
        throw(std::runtime_error("ERROR, first and second elements must be numbers"));
    for(size_t i = 0; i < expression.size(); i++)
    {
        if(!isdigit(expression[i]) && !isOperator(expression[i]) && expression[i] != ' ' )
            throw(std::runtime_error("ERROR, member is not a number nor an operator"));
        
        // std::cout << "oumourna wadh7a\n";
    }
}

void RPN::calculate(std::string expression)
{
    int a;
    int b;
    size_t i = 0;
    while (i < expression.size())
    {
        if (isdigit(expression[i]))
        {
            std::string member;
            member = expression.substr(i, 1);
            a = atoi(member.c_str());
            _mem.push(a);
        }
        if (isOperator(expression[i]))
        {
            int res;
            b = _mem.top();
            _mem.pop();
            a = _mem.top();
            _mem.pop();
            res = doRPN(a, b, expression[i]);
            _mem.push(res);
        }
        i++;
    }
    std::cout << "hello\n";
    printStack(_mem);
}

int RPN::doRPN(int a, int b, char op)
{
    int res;

    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if( op == '*')
        res = a * b;
    else
    {
        if (b == 0)
            throw(std::runtime_error("impossible to divide by 0"));
        else
            res = a / b;
    }
    return(res);
}
