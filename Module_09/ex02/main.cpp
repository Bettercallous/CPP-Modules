#include "PmergeMe.hpp"

void mergeInsertSortList(std::list<unsigned int>& lst) {
    if (lst.size() <= 1)
        return;

    std::list<unsigned int>::iterator it = lst.begin();
    while (it != lst.end()) {
        std::list<unsigned int>::iterator next = it;
        ++next;
        if (next != lst.end() && *it > *next)
            std::iter_swap(it, next);
        ++it;
    }

    std::list<unsigned int> sorted_half;
    std::list<unsigned int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    sorted_half.splice(sorted_half.begin(), lst, mid, lst.end());
    mergeInsertSortList(sorted_half);

    std::list<unsigned int>::iterator it_sorted = sorted_half.begin();
    while (it_sorted != sorted_half.end()) {
        std::list<unsigned int>::iterator insert_pos = lst.begin();
        while (insert_pos != lst.end() && *insert_pos < *it_sorted)
            ++insert_pos;
        lst.insert(insert_pos, *it_sorted);
        ++it_sorted;
    }
}

void mergeInsertSortVec(std::vector<unsigned int>& numbers) {
    if (numbers.size() <= 1)
        return;
 
    for (size_t i = 0; i < numbers.size() - 1; i += 2) {
        if (numbers[i] > numbers[i + 1])
            std::swap(numbers[i], numbers[i + 1]);
    }

    std::vector<unsigned int> sorted_half(numbers.begin() + numbers.size() / 2, numbers.end());

    mergeInsertSortVec(sorted_half);

    for (size_t i = 0; i < numbers.size() / 2; i++) {
        // upper_bound uses binary search
        size_t insert_pos = std::distance(sorted_half.begin(), std::upper_bound(sorted_half.begin(), sorted_half.end(), numbers[i]));
        sorted_half.insert(sorted_half.begin() + insert_pos, numbers[i]);
    }

    numbers = sorted_half;
}

bool parseInput(std::vector<unsigned int>& numbers, int ac, char **av) {
    
    std::string tmp;
    for (int i = 1; i < ac; i++) {
        tmp = av[i];
        if (tmp.find_first_not_of("0123456789 ") != std::string::npos) {
            std::cerr << "Error: invalid input" << std::endl;
            return false;
        }

        unsigned int x;
        std::string buf;
        std::istringstream iss(tmp);

        while (getline(iss, buf, ' ')) {
            if (!buf.empty()) {
                std::istringstream(buf) >> x;
                numbers.push_back(x);
            }
        }
    }

    return true;
}

void print(unsigned int x) {std::cout << x << " ";}

void printmsg(const std::vector<unsigned int>& vec, const std::string& msg) {
    std::cout << msg;
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe _positive_integer_sequence_" << std::endl;
        return 1;
    }
    
    std::vector<unsigned int> vec;
    if (parseInput(vec, ac, av) == false)
        return 1;
    std::list<unsigned int> list(vec.begin(), vec.end());
    
    printmsg(vec, "Before: ");

    clock_t start = clock();
    mergeInsertSortVec(vec);
    clock_t end = clock();

    printmsg(vec, "After: ");

    double vectorDuration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

    start = clock();
    mergeInsertSortList(list);
    end = clock();

    double listDuration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vectorDuration << " µs" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list   : " << listDuration << " µs" << std::endl;

    return 0;
}
