#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Zombie {
public:
	explicit Zombie(const std::string& name);
	~Zombie();

	void announce(void) const;

private:
	std::string name;
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif
