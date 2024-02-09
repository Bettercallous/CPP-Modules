#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other) {*this = other;}

PmergeMe& PmergeMe::operator=(const PmergeMe & other) {
    if (this != &other) {
        _vec = other._vec;
        _deck = other._deck;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge(std::vector<std::pair<int, int> >& vec, std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right) {

	size_t i = 0, l = 0, r = 0;
	size_t leftSize = left.size(), rightSize = right.size();

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

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
      return;

    int mid = pairs.size() / 2;

    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    mergeSort(left);
    mergeSort(right);

    merge(pairs, left, right);
}

void PmergeMe::merge(std::deque<std::pair<int, int> >& vec, std::deque<std::pair<int, int> >& left, std::deque<std::pair<int, int> >& right) {

	size_t i = 0, l = 0, r = 0;
	size_t leftSize = left.size(), rightSize = right.size();

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

void PmergeMe::mergeSort(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
      return;

    int mid = pairs.size() / 2;

    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
    
    mergeSort(left);
    mergeSort(right);

    merge(pairs, left, right);
}

void PmergeMe::mergeInsertSortVec() {

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < _vec.size(); i += 2) {
        if (i + 1 < _vec.size())
            pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
        else
            pairs.push_back(std::make_pair(_vec[i], -1));
    }

    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    mergeSort(pairs);

    _vec.clear();
    if (pairs[0].second != -1)
	    _vec.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		_vec.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].second != -1) {
		    std::vector<int>::iterator it = std::lower_bound(_vec.begin(), _vec.end(), pairs[i].second);   
		    _vec.insert(it, pairs[i].second);
        }
    }
}

void PmergeMe::mergeInsertSortDeck() {

    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < _deck.size(); i += 2) {
        if (i + 1 < _deck.size())
            pairs.push_back(std::make_pair(_deck[i], _deck[i + 1]));
        else
            pairs.push_back(std::make_pair(_deck[i], -1));
    }

    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    mergeSort(pairs);

    _deck.clear();
    if (pairs[0].second != -1)
	    _deck.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++) {
		_deck.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); i++) {
        if (pairs[i].second != -1) {
		    std::deque<int>::iterator it = std::lower_bound(_deck.begin(), _deck.end(), pairs[i].second);
		    _deck.insert(it, pairs[i].second);
        }
    }
}

std::pair<double, double> PmergeMe::sort() {

    clock_t start = clock();
    mergeInsertSortVec();
    clock_t end = clock();

    clock_t start2 = clock();
    mergeInsertSortDeck();
    clock_t end2 = clock();

    double vectorDuration = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;
    double deckDuration = ((double)(end2 - start2) / CLOCKS_PER_SEC) * 1000000;

    return std::make_pair(vectorDuration, deckDuration);
}

bool PmergeMe::parseInput(int ac, char **av) {

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
                _vec.push_back(x);
                _deck.push_back(x);
            }
        }
    }

    return true;
}

void PmergeMe::printElements(const std::string& msg) const {
    std::cout << msg;
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;
}

size_t PmergeMe::getVecSize() const {
    return _vec.size();    
}

size_t PmergeMe::getDequeSize() const {
    return _deck.size();
}
