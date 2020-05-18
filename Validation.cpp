#include "Validation.h"
#include "BadInput.h"
#include <iostream>

using namespace std;

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


std::string Validation::validateCycle(std::string text, std::string& input, std::string type) {
    // Validating the input
    bool firstTime = true;
    while (true) {
        try {
            if (type == "inputUI") {
                cout << text;
                cout << "\n\nInput: "; cin >> input;
                if (validate_inputUI(input) == false)
                    throw BadInput("inputUI");
                else
                    break;
            }
            else if (type == "inputUI_user") {
                cout << text;
                cout << "\nInput: "; cin >> input;
                if (validate_inputUI_user(input) == false)
                    throw BadInput("inputUI_user");
                else
                    break;
            }

            else if (type == "inputUI_3") {
                cout << text;
                cout << "\nInput: "; cin >> input;
                if (validate_inputUI_3(input) == false)
                    throw BadInput("inputUI_3");
                else
                    break;
            }

            else if (type == "inputUI_admin") {
                cout << text;
                cout << "\nInput: "; cin >> input;
                if (validate_inputUI_admin(input) == false)
                    throw BadInput("inputUI_admin");
                else
                    break;
            }
            else if (type == "titel") {
                cout << "\nIf 'enter Title:' does not appear, press enter";
                if(firstTime == true)
                    cin.ignore(1000, '\n');
                cout << "\nEnter Title: ";
                getline(cin, input);
                try {
                    if (validate_inputUi_number(input) == true)
                        throw BadInput("titel");
                    else break;
                }
                catch (BadInput& b) {
                    cout << b.what();
                }
                firstTime = false;
            }
            else if (type == "genre") {
                cout << "\nIf 'enter Genre:' does not appear, press enter";
                if (firstTime == true)
                    cin.ignore(1000, '\n');
                cout << "\nEnter Genre: ";
                getline(cin, input);
                try {
                    if (validate_inputUi_number(input) == true)
                        throw BadInput("genre");
                    else break;
                }
                catch (BadInput& b) {
                    cout << b.what();
                }
                firstTime = false;
            }
            else if (type == "trailer") {
                cout << "\nIf 'enter Trailer:' does not appear, press enter";
                if (firstTime == true)
                    cin.ignore(1000, '\n');
                cout << "\nEnter Trailer: ";
                getline(cin, input);
                try {
                    if (validate_inputUi_number(input) == true)
                        throw BadInput("trailer");
                    else break;
                }
                catch (BadInput& b) {
                    cout << b.what();
                }
                firstTime = false;
            }
            else if (type == "jahr") {
                cout << "\nEnter Jahr: "; cin >> input;
                try {
                    double d_input = stod(input);
                    if (validate_inputUi_jahr(d_input) == false)
                        throw BadInput("jahr");
                    else break;
                }
                catch (BadInput& b) {
                    cout << b.what();
                }
                catch (invalid_argument invalid) {
                    BadInput b("jahr");
                    cout << b.what();
                }
            }
            else if (type == "likes") {
                cout << "\nEnter Likes: "; cin >> input;
                try {
                    if (validate_inputUi_number(input) == false)
                        throw BadInput("likes");
                    else break;
                }
                catch (BadInput& b) {
                    cout << b.what();
                }
            }
        }
        catch (BadInput& b) {
            cout << b.what();
        }
    }
    return input;
}