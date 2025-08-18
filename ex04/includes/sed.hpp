#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool		read_file(const std::string& path, std::string& out);
bool		write_file(const std::string& path, const std::string& data);
std::string	replace_all(const std::string& text,
						 const std::string& s1,
						 const std::string& s2);

#endif
