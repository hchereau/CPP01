#include "Zombie.hpp"

int main() {
	Zombie* horde = new Zombie[3];
	for (int i = 0; i < 3; ++i) {
		horde[i].setName("Zed");
		horde[i].announce();
	}
	delete[] horde;
}
