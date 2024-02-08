#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <sys/time.h>

std::pair<double, double> sort(std::vector<int>& vec, std::deque<int>& deck);
bool parseInput(std::vector<int>& numbers, int ac, char **av);
void printElements(const std::vector<int>& vec, const std::string& msg);

#endif