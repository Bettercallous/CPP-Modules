#include "Sed.hpp"

void replaceOccurrence(const std::string& filename, const std::string& s1, const std::string& s2) {

	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		std::cerr << "Error: Couldn't open the file." << std::endl;
		return;
	}

	std::ostringstream buffContent;
	buffContent << inputFile.rdbuf();
	std::string fileContent = buffContent.str();
	inputFile.close();

	size_t startPos = 0;
	if (!s1.empty() && s1 != s2) {
		while ((startPos = fileContent.find(s1, startPos)) != std::string::npos) {
			fileContent = fileContent.substr(0, startPos) + s2 + fileContent.substr(startPos + s1.length());
			startPos += s2.length();
		}
	}

	std::ofstream outputFile((filename + ".replace"));
	if (!outputFile.is_open()) {
		std::cerr << "Error: Couldn't create the output file." << std::endl;
		return;
	}

	outputFile << fileContent;
	outputFile.close();

	std::cout << "Replacement completed. Output written to " << filename + ".replace" << std::endl;
}
