#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN & other);
        RPN& operator=(const RPN & other);
        ~RPN();

        bool processExpression(const std::string& input);
        int executeExpression(const std::string& expr);
};


#endif