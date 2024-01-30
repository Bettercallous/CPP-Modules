#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {*this = other;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange & other) {
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        if (std::getline(iss, dateStr, ',') && std::getline(iss, valueStr)) {
            double value;
            std::istringstream(valueStr) >> value;
            std::string key = trim(dateStr);
            exchangeRates[key] = value;
        }
    }

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (exchangeRates.empty()) {
        return -1;
    }

    // Find the first date greater than or equal to the input date
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    // Check if exact date found
    if (it != exchangeRates.end() && it->first == date) {
        return it->second; // Found exact date, return its rate
    }

    // No exact match, check if before first entry
    if (it == exchangeRates.begin()) {
        return -1; // Date comes before earliest recorded date
    }

    // Use the previous date as it's the closest
    --it;
    return it->second; // Return rate of closest earlier date
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
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;

    while (std::getline(iss, token, '|')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 2) {
        std::cout << "Error: bad input => " << input << std::endl;
        return std::make_pair(false, std::make_pair("", 0));
    }

    double value;
    if (BitcoinExchange::checkValue(value, tokens[1]) == -1) {
        return std::make_pair(false, std::make_pair("", 0));
    }

    if (BitcoinExchange::checkDate(tokens[0]) == -1) {
        return std::make_pair(false, std::make_pair("", 0));
    }
    
    return std::make_pair(true, std::make_pair(BitcoinExchange::trim(tokens[0]), value));
}

int BitcoinExchange::checkValue(double& value, const std::string& valueStr) {
    std::string str = BitcoinExchange::trim(valueStr);
    std::istringstream buf(str);
    // std::cout << valueStr << isNumeric(valueStr) << std::endl;
    if (isNumeric(str, ".0123456789") == false) {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }
    // Check if the string is empty

    // Check for multiple decimal points
    if (std::count(str.begin(), str.end(), '.') > 1) {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }

    // Check if the string starts with a decimal point
    if (str[0] == '.') {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }

    // Check if the string ends with a decimal point
    if (str[str.length() - 1] == '.') {
        std::cerr << "Error: invalid number => " << buf.str() << std::endl;
        return -1;
    }
    buf >> value;
    // cant be negative because of isNumeric function above
    if (value > 1000) {
        std::cerr << "Error: number too large." << std::endl;
        return -1;
    }

    return 0;
}

int BitcoinExchange::checkDate(const std::string& date) {
    std::vector<std::string> tokens;
    std::istringstream iss(BitcoinExchange::trim(date));
    std::string token;

    while (std::getline(iss, token, '-')) {
        tokens.push_back(token);
    }
    if (tokens.size() != 3) {
        std::cerr << "Error: invalid date." << std::endl;
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        if (isNumeric(tokens[i], "0123456789") == false) {
            std::cout << "alo\n";
            std::cerr << "Error: invalid date." << std::endl;
            return -1;
        }
    }
    int tmp;
    std::istringstream(tokens[0]) >> tmp;
    if (tmp < 2009 || tmp > 2022) {
        std::cerr << "Error: invalid date." << std::endl;
        return -1;
    }

    std::istringstream(tokens[1]) >> tmp;
    if (tmp <= 0 || tmp > 12) {
        std::cerr << "Error: invalid date." << std::endl;
        return -1;
    }

    std::istringstream(tokens[2]) >> tmp;
    if (tmp <= 0 || tmp > 31) {
        std::cerr << "Error: invalid date." << std::endl;
        return -1;
    }
    return 1;
}