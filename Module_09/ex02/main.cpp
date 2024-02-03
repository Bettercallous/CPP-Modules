#include "PmergeMe.hpp"

void mergeInsertSort(std::vector<unsigned int>& numbers) {
    // Base case: if the vector has less than or equal to one element, it's already sorted
    if (numbers.size() <= 1)
        return;

    // Sort pairs by comparing and swapping if necessary
    for (size_t i = 0; i < numbers.size() - 1; i += 2) {
        if (numbers[i] > numbers[i + 1])
            std::swap(numbers[i], numbers[i + 1]);
    }

    // Recursively sort the larger elements
    std::vector<unsigned int> sorted_half(numbers.begin() + numbers.size() / 2, numbers.end());
    mergeInsertSort(sorted_half);

    // Insert the remaining elements into the sorted sequence
    for (size_t i = 0; i < numbers.size() / 2; i++) {
        // Perform binary search to find the insertion position
        size_t insert_pos = std::upper_bound(sorted_half.begin(), sorted_half.end(), numbers[i]) - sorted_half.begin();

        // Insert the element at the found position
        sorted_half.insert(sorted_half.begin() + insert_pos, numbers[i]);
    }

    // Update the input vector with the sorted sequence
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

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe _positive_integer_sequence_" << std::endl;
        return 1;
    }
    
    std::vector<unsigned int> numbers;

    if (parseInput(numbers, ac, av) == false)
        return 1;

    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    mergeInsertSort(numbers);

    std::cout << "After: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*

Merge-insertion sort performs the following steps, on an input X of n elements:

1. Group the elements of X into [n/2] pairs of elements, arbitrarily, leaving one element unpaired if there is an odd number of elements.
2. Perform [n/2] comparisons, one per pair, to determine the larger of the two elements in each pair.
3. Recursively sort the [n/2] larger elements from each pair, creating a sorted sequence S of [n/2] of the input elements, in ascending order.
4. Insert at the start of S the element that was paired with the first and smallest element of S.
5. Insert the remaining [n/2] - 1 elements of X into S, one at a time, with a specially chosen insertion ordering described below.
Use binary search in subsequences of S to determine the position at which each element should be inserted.

*/