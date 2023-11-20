#include "SearchAndReplace.hpp"

void replaceOccurrence(const std::string& filename, const std::string& s1, const std::string& s2) {

	// Open and Read the File
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open()) {
		std::cerr << "Error: Couldn't open the file." << std::endl;
		return;
	}

	std::ostringstream buffContent;
	buffContent << inputFile.rdbuf(); // reads the entire content from the file buffer
	std::string fileContent = buffContent.str();
	inputFile.close();

	// String Replacement
	size_t startPos = 0;
	if (!s1.empty() && s1 != s2) {
		while ((startPos = fileContent.find(s1, startPos)) != std::string::npos) {
			fileContent = fileContent.substr(0, startPos) + s2 + fileContent.substr(startPos + s1.length());
			startPos += s2.length();
		}
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

/*
	When you open a file using an input file stream (std::ifstream), the file's data is read into an internal buffer
	managed by the stream. This buffer is filled with data from the file, and you can access
	it using the rdbuf() function, which returns a pointer to this internal file stream buffer.
*/

/*
	std::ostringstream	represents an output stream that writes its data to a string. It's akin to a special box
	where you can add different pieces of information and then later use all those pieces to create a single string.
*/