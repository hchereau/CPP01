#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
public:
	Harl();
	~Harl();

	void complain(const std::string& level) const;

private:

	enum Level {
		DEBUG_L = 0,
		INFO_L,
		WARNING_L,
		ERROR_L,
		UNKNOWN_L
	};

	void debug() const;
	void info() const;
	void warning() const;
	void error() const;

	Level toLevel(const std::string& level) const;


	typedef void (Harl::*Handler)() const;


	static const char*  kLevelNames[4];
	static const Handler kHandlers[4];
};

#endif
