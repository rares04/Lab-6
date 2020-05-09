#pragma once
#include <string>

class Validation {
public:
	// Validates input from the main page
	bool validate_inputUI(std::string);

	// Validates input for user Actions
	bool validate_inputUI_user(std::string);

	// Validates input for admin Actions
	bool validate_inputUI_admin(std::string);

	// Validates input for User Action 1
	bool validate_inputUI_3(std::string);

	// Validates input for numbers
	bool validate_inputUi_number(const std::string& s);

	// Validates the input for the year
	bool validate_inputUi_jahr(double jahr);
	
	// Uses all of the above functions
	std::string validateCycle(std::string text, std::string& input, std::string type);
};

