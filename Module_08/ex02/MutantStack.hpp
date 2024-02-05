#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T, container> {
    public:
        MutantStack() : std::stack<T, container>() {}
        MutantStack(const MutantStack& other) : std::stack<T, container>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other)
                std::stack<T, container>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        typedef typename container::iterator iterator;
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
};

#endif