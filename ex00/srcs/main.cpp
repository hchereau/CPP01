#include "Zombie.hpp"

int	main(){
	Zombie*	heapZombie = newZombie("HeadZed");
	heapZombie->announce();
	delete heapZombie;
	randomChump("StackZes");
	return EXIT_SUCCESS;
}
