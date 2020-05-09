#pragma once
#include <exception>
#include <string>
class BadInput : public std::exception {
private:
	std::string message;
public:
	// Default constructor
	BadInput();

	// Constructor with parameter
	BadInput(std::string _type);

	// What method
	const char* what() const;
};

