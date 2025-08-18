#include "sed.hpp"

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << (argc ? argv[0] : "sed")
				  << " <filename> <s1> <s2>\n";
		return 1;
	}
	const std::string in = argv[1], s1 = argv[2], s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty.\n";
		return 1;
	}
	std::string content;
	if (!read_file(in, content)) {
		std::cerr << "Error: cannot open input file: " << in << "\n";
		return 1;
	}
	const std::string out = replace_all(content, s1, s2);
	if (!write_file(in + ".replace", out)) {
		std::cerr << "Error: cannot write output file.\n";
		return 1;
	}
	return 0;
}
