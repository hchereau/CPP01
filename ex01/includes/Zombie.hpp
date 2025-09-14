#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Zombie {
public:
	Zombie();
	explicit Zombie(const std::string& name);
	~Zombie();
	void	announce(void) const;
	void	setName(const std::string& name);

private:
	std::string name;
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);
Zombie*	zombieHorde(const int N, const std::string& name);

#endif
