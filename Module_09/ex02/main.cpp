#include "PmergeMe.hpp"

void merge(std::vector<std::pair<int, int> >& vec, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right) {

	size_t i = 0, l = 0, r = 0;
	size_t leftSize = left.size(), rightSize = right.size();
 
	// while there are elements within both right and left vectors
	while (l < leftSize && r < rightSize) {
		if (left[l].first < right[r].first)
			vec[i++] = left[l++];
		else
			vec[i++] = right[r++];
	}

	while (l < leftSize) {
		vec[i++] = left[l++];
	}

	while (r < rightSize) {
		vec[i++] = right[r++];
	}

}

void mergeSort(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
      return;

    int mid = pairs.size() / 2;

    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
    
    mergeSort(left);
    mergeSort(right);

    merge(pairs, left, right);
}


std::vector<int> mergeInsertSortVec(std::vector<int>& numbers) {

    std::vector<std::pair<int, int> > pairs;
    pairs.reserve(numbers.size() / 2 + numbers.size() % 2);

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size())
            pairs.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        else
            pairs.push_back(std::make_pair(numbers[i], -1));
    }

    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    mergeSort(pairs);

	std::vector<int> mainChain;
	mainChain.reserve(numbers.size()); // 

	mainChain.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); i++) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);
		mainChain.insert(it, pairs[i].second);
    }

	return mainChain;
}

bool parseInput(std::vector<int>& numbers, int ac, char **av) {
    
    std::string tmp;
    for (int i = 1; i < ac; i++) {
        tmp = av[i];
        if (tmp.find_first_not_of("0123456789 ") != std::string::npos) {
            std::cerr << "Error: invalid input" << std::endl;
            return false;
        }

        int x;
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

void print(int x) {std::cout << x << " ";}

void printmsg(const std::vector<int>& vec, const std::string& msg) {
    std::cout << msg;
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Usage: ./PmergeMe _positive_integer_sequence_" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    if (parseInput(vec, ac, av) == false)
        return 1;

    printmsg(vec, "Before: ");

    clock_t start = clock();
    std::vector<int> sorted = mergeInsertSortVec(vec);
    clock_t end = clock();

    printmsg(sorted, "After: ");

    double vectorDuration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vectorDuration << " µs" << std::endl;
    // std::cout << "Time to process a range of " << list.size() << " elements with std::list   : " << listDuration << " µs" << std::endl;

    return 0;
}
