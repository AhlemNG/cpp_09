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

RPN::RPN(std::string &expression)
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
    for(size_t i = 0; i < expression.size(); i++)
    {
        if(!isdigit(expression[i]) && !isOperator(expression[i]) && expression[i] != ' ' )
            throw(std::runtime_error("ERROR"));
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
            if (_mem.size() < 2)
                throw(std::runtime_error("Error"));
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
    if(_mem.size() != 1)
        throw(std::runtime_error("Error"));
    printStack(_mem);
}

int RPN::doRPN(int a, int b, char op)
{
    long long res;

    if (op == '+')
        res = static_cast<long long>(a) + static_cast<long long>(b);
    else if (op == '-')
        res = static_cast<long long>(a) - static_cast<long long>(b);
    else if( op == '*')
        res = static_cast<long long>(a) * static_cast<long long>(b);
    else
    {
        if (static_cast<long long>(b) == 0)
            throw(std::runtime_error("Error: division by 0"));
        else
            res = static_cast<long long>(a) / static_cast<long long>(b);
    }
    if (res > std::numeric_limits<int>::max() || res <= std::numeric_limits<int>::min())
        throw(std::runtime_error("Error: overflow"));
    return(static_cast<int>(res));
}
