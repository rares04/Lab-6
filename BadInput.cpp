#include "BadInput.h"


BadInput::BadInput() {
	message = "Bad input";
}


BadInput::BadInput(std::string _type) {
	if (_type == "inputUI")
		message = "\nInput was not correct, please choose between 0, 1 and 2\n\n";
	if (_type == "inputUI_user")
		message = "\nInput was not correct, please choose between 1, 2, 3 and 4\n\n";
	if (_type == "inputUI_3")
		message = "\nInput was not correct, please choose between  1, 2, and 3\n\n";
	if (_type == "inputUI_admin")
		message = "\nInput was not correct, please choose between 1, 2, 3, 4 and  5\n\n";
	if (_type == "titel")
		message = "\nInput was not correct, please choose a non numeric name\n\n";
	if (_type == "genre")
		message = "\nInput was not correct, please choose a non numeric genre\n\n";
	if (_type == "jahr")
		message = "\nInput was not correct, please choose a correct number between 0 and 2020\n\n";
	if (_type == "likes")
		message = "\nInput was not correct, please choose a number for likes\n\n";
	if (_type == "trailer")
		message = "\nInput was not correct, please choose a correct url\n\n";
}


const char* BadInput::what() const {
	return message.c_str();
}



