#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <sys/time.h>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deck;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe & other);
        PmergeMe& operator=(const PmergeMe & other);
        ~PmergeMe();

        size_t getVecSize() const;
        size_t getDequeSize() const;
        void printElements(const std::string& msg) const;

        bool parseInput(int ac, char **av);
        std::pair<double, double> sort();
        void mergeInsertSortDeck();
        void mergeInsertSortVec();
        void mergeSort(std::deque<std::pair<int, int> >& pairs);
        void mergeSort(std::vector<std::pair<int, int> >& pairs);
        void merge(std::deque<std::pair<int, int> >& vec, std::deque<std::pair<int, int> >& left, std::deque<std::pair<int, int> >& right);
        void merge(std::vector<std::pair<int, int> >& vec, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right);
};

#endif