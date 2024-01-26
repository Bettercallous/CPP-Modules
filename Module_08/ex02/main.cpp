#include "MutantStack.hpp"
#include <cassert>

void subjectTest()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void myTests() {
    MutantStack<int> mstack;

    // Test pushing elements
    mstack.push(5);
    mstack.push(10);
    mstack.push(15);

    // Test size
    assert(mstack.size() == 3);

    // Test top element
    assert(mstack.top() == 15);

    // Test popping elements
    mstack.pop();
    assert(mstack.top() == 10);
    mstack.pop();
    assert(mstack.top() == 5);
    mstack.pop();

    // Test empty stack
    assert(mstack.empty());

    // Test iteration
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    int sum = 0;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        sum += *it;
    }
    assert(sum == 6); // 1 + 2 + 3 = 6
}

int main()
{
    subjectTest();
    myTests();
    std::cout << "All tests passed successfully!" << std::endl;
}