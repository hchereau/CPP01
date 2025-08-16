#include <string>
#include <iostream>

int main(){
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Memory address of str:            " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string:     " << str << std::endl;
	std::cout << "Value pointed by PTR:" << *stringPTR << std::endl;
	std::cout << "Value by stringREF  :" << stringREF << std::endl;
}
