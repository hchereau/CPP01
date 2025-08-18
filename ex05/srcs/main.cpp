#include "harl.hpp"

int main() {
	Harl h;

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERROR");
	h.complain("NOPE");

	return 0;
}
