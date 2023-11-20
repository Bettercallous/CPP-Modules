#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		std::string level[4];
		typedef void(Harl::*funcPTR)();
		void debug();
		void info();
		void warning();
		void error();
		funcPTR funcPTRS[4];
	public:
		Harl();
		void complain(std::string level);
};

#endif