#include "Zombie.hpp"

int main(int ac, char **av) {

	if (ac != 3){
		std::cout << "error: usage: ./ZombieHorde <number_of_zombies> <name_of_zombies>\n" << std::endl;
		return EXIT_FAILURE;
	}
	int	n = std::atoi(av[1]);
	if (n <= 0){
		std::cout << "error: number of zombies can't be negative\n" << std::endl;
		return EXIT_FAILURE;
	}
	Zombie*	horde = zombieHorde(n, av[2]);
	for (int i = 0; i < n; i++){
		horde[i].announce();
	}
	delete[] horde;
	return EXIT_SUCCESS;
}
