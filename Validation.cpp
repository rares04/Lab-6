#include "Validation.h"


bool Validation::validate_inputUI(std::string input) {
	if (input != "0" and input != "1" and input != "2")
		return false;
	return true;
}


bool Validation::validate_inputUI_user(std::string input) {
	if (input != "1" and input != "2" and input != "3" and input != "4")
		return false;
	return true;
}


bool Validation::validate_inputUI_3(std::string input) {
	if (input != "1" and input != "2" and input != "3")
		return false;
	return true;
}


bool Validation::validate_inputUI_admin(std::string input) {
	if (input != "1" and input != "2" and input != "3" and input != "4" and input != "5")
		return false;
	return true;
}

bool Validation::validate_inputUi_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool Validation::validate_inputUi_jahr(double jahr){
    return jahr > 0 && jahr <= 2020 && jahr == (int)jahr;
}
