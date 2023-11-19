#include "SearchAndReplace.hpp"

void replaceOccurrence(const std::string& filename, const std::string& s1, const std::string& s2) {
	
	// Open and Read the File
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open()) {
		std::cerr << "Error: Couldn't open the file." << std::endl;
		return;
	}

	std::ostringstream contentStream;
	contentStream << inputFile.rdbuf();
	std::string fileContent = contentStream.str();
	inputFile.close();

	// String Replacement
	size_t startPos = 0;
	while ((startPos = fileContent.find(s1, startPos)) != std::string::npos) {
		fileContent = fileContent.substr(0, startPos) + s2 + fileContent.substr(startPos + s1.length());
		startPos += s2.length();
	}

	// Write Modified Content to a New File
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Couldn't create the output file." << std::endl;
		return;
	}

	outputFile << fileContent;
	outputFile.close();

	std::cout << "Replacement completed. Output written to " << filename + ".replace" << std::endl;
}

void inputCheck(std::string& input) {
	if (std::cin.eof()) {
		std::cout << std::endl;
		exit (0);
	}
	while (input.empty()) {
		std::cout << "Field can not be empty: ";
		getline(std::cin, input);
        if (std::cin.eof()) {
	    	std::cout << std::endl;
		    exit (0);
        }
	}
}
