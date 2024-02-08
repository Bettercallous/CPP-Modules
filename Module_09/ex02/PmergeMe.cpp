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

void merge(std::deque<std::pair<int, int> >& vec, std::deque<std::pair<int, int> >& left, std::deque<std::pair<int, int> >& right) {

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

void mergeSort(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
      return;

    int mid = pairs.size() / 2;

    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
    
    mergeSort(left);
    mergeSort(right);

    merge(pairs, left, right);
}

void mergeInsertSortVec(std::vector<int>& numbers) {

    std::vector<std::pair<int, int> > pairs;

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

    numbers.clear();
    if (pairs[0].second != -1)
	    numbers.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		numbers.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].second != -1) {
		    std::vector<int>::iterator it = std::lower_bound(numbers.begin(), numbers.end(), pairs[i].second);   
		    numbers.insert(it, pairs[i].second);
        }
    }
}

void mergeInsertSortDeck(std::deque<int>& numbers) {

    std::deque<std::pair<int, int> > pairs;

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

    numbers.clear();
    if (pairs[0].second != -1)
	    numbers.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		numbers.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].second != -1) {
		    std::deque<int>::iterator it = std::lower_bound(numbers.begin(), numbers.end(), pairs[i].second);
		    numbers.insert(it, pairs[i].second);
        }
    }
}

std::pair<double, double> sort(std::vector<int>& vec, std::deque<int>& deck) {

    clock_t start = clock();
    mergeInsertSortVec(vec);
    clock_t end = clock();

    clock_t start2 = clock();
    mergeInsertSortDeck(deck);
    clock_t end2 = clock();

    double vectorDuration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;
    double deckDuration = ((double)(end2 - start2) / CLOCKS_PER_SEC) * 1000000;

    return std::make_pair(vectorDuration, deckDuration);
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

void printElements(const std::vector<int>& vec, const std::string& msg) {
    std::cout << msg;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
