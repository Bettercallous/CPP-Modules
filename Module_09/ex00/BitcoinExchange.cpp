#include "BitcoinExchange.hpp"

bool flag = false;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {*this = other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other) {
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        return false;
    }

    std::string line;
    std::getline(file, line); //skip first line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, ',') && std::getline(iss, valueStr)) {
            double value;
            std::istringstream(valueStr) >> value;
            std::string key = trim(dateStr);
            _exchangeRates[key] = value;
        }
    }

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {

    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }

    if (it == _exchangeRates.begin()) {
        return -1;
    }

    --it;
    return it->second;
}

std::string BitcoinExchange::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

static bool isNumeric(const std::string& str, const std::string& sequence) {
    return str.find_first_not_of(sequence) == std::string::npos;
}

std::pair<bool, std::pair<std::string, double> > BitcoinExchange::parseInput(const std::string& input) {
    std::list<std::string> tokens;
    std::string str = trim(input);
    std::istringstream iss(str);
    std::string token;

    if (str[0] == '|' || str[str.length() - 1] == '|') {
        std::cout << "Error: bad input => " + input << std::endl;
        return std::make_pair(false, std::make_pair("", 0));
    }

    while (std::getline(iss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 2) {
        std::cerr << "Error: bad input => " + input << std::endl;
        return std::make_pair(false, std::make_pair("", 0));
    }

    std::list<std::string>::iterator it = tokens.begin();
    std::string key = trim(*it);
    std::advance(it, 1);
    std::string val = trim(*it);

    if (key == "date" && val == "value") {
        if (flag == true) {
            std::cerr << "Error: bad input => " + input << std::endl;
        }
        return std::make_pair(false, std::make_pair("", 0));
    }

    double value;
    if (checkValue(value, val) == false) {
        return std::make_pair(false, std::make_pair("", 0));
    }

    if (checkDate(key) == false) {
        return std::make_pair(false, std::make_pair("", 0));
    }

    return std::make_pair(true, std::make_pair(key, value));
}

bool BitcoinExchange::checkValue(double& value, const std::string& valueStr) {

    if (isNumeric(valueStr, ".0123456789") == false) {
        std::cerr << "Error: invalid number => " + valueStr << std::endl;
        return false;
    }

    if (std::count(valueStr.begin(), valueStr.end(), '.') > 1) {
        std::cerr << "Error: invalid number => " + valueStr << std::endl;
        return false;
    }

    if (valueStr[0] == '.') {
        std::cerr << "Error: invalid number => " + valueStr << std::endl;
        return false;
    }

    if (valueStr[valueStr.length() - 1] == '.') {
        std::cerr << "Error: invalid number => " + valueStr << std::endl;
        return false;
    }

    std::istringstream(valueStr) >> value;
    if (value > 1000) {
        std::cerr << "Error: number too large." << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::checkDate(const std::string& date) {
    std::list<std::string> tokens;
    std::istringstream iss(date);
    std::string token;

    while (std::getline(iss, token, '-')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 3) {
        std::cerr << "Error: invalid date => " + date << std::endl;
        return false;
    }

    for (std::list<std::string>::iterator itr = tokens.begin(); itr != tokens.end(); ++itr) {
        if (isNumeric(*itr, "0123456789") == false) {
            std::cerr << "Error: invalid date => " + date << std::endl;
            return false;
        }
    }

    std::list<std::string>::iterator it = tokens.begin();
    std::string year(*it);
    std::string month(*(++it));
    std::string day(*(++it));

    if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
        std::cerr << "Error: invalid date => " + date << std::endl;
        return false;
    }

    int tmp;
    std::istringstream(year) >> tmp;
    if (tmp < 2009 || tmp > 2022) {
        std::cerr << "Error: invalid date => " + date << std::endl;
        return false;
    }

    std::istringstream(month) >> tmp;
    if (tmp <= 0 || tmp > 12) {
        std::cerr << "Error: invalid date => " + date << std::endl;
        return false;
    }

    std::istringstream(day) >> tmp;
    if (tmp <= 0 || tmp > 31) {
        std::cerr << "Error: invalid date => " + date << std::endl;
        return false;
    }
    return true;
}