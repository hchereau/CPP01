#include "sed.hpp"

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << (argc ? argv[0] : "sed")
				  << " <filename> <s1> <s2>" << std::endl;
		return EXIT_FAILURE;
	}
	const std::string in = argv[1], s1 = argv[2], s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty." << std:: endl;
		return EXIT_FAILURE;
	}
	std::string content;
	if (!read_file(in, content)) {
		std::cerr << "Error: cannot open input file: " << in << std::endl;
		return EXIT_FAILURE;
	}
	const std::string out = replace_all(content, s1, s2);
	if (!write_file(in + ".replace", out)) {
		std::cerr << "Error: cannot write output file." << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
