#include "harl.hpp"

// ----- Tables de dispatch -----
// (ordre strictement identique pour noms et handlers)
const char* Harl::kLevelNames[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
const Harl::Handler Harl::kHandlers[4] = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

// ----- Ctor / Dtor -----
Harl::Harl() {}
Harl::~Harl() {}

// ----- Public -----
void Harl::complain(const std::string& level) const {
	Level L = toLevel(level);
	if (L == UNKNOWN_L) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	// Appel direct via la table de pointeurs-méthodes
	(this->*kHandlers[L])();
}

// ----- Privé : mapping -----
Harl::Level Harl::toLevel(const std::string& level) const {
	for (int i = 0; i < 4; ++i) {
		if (level == kLevelNames[i]) {
			return static_cast<Level>(i);
		}
	}
	return UNKNOWN_L;
}

// ----- Privé : handlers -----
void Harl::debug() const {
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
		<< "I really do!"
		<< std::endl;
}

void Harl::info() const {
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning() const {
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error() const {
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

