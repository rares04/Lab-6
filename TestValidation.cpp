#include "TestValidation.h"
#include "BadInput.h"
#include <cassert>
#include <iostream>

void TestValidation::Testvalidate_inputUI() {
	assert(valid.validate_inputUI("0") == true);
	assert(valid.validate_inputUI("1") == true);
	assert(valid.validate_inputUI("2") == true);

	assert(valid.validate_inputUI("3") == false);
	assert(valid.validate_inputUI("00") == false);
	assert(valid.validate_inputUI("4") == false);
	assert(valid.validate_inputUI("") == false);
	assert(valid.validate_inputUI("input") == false);
}


void TestValidation::Testvalidate_inputUI_user() {
	assert(valid.validate_inputUI_user("1") == true);
	assert(valid.validate_inputUI_user("2") == true);
	assert(valid.validate_inputUI_user("3") == true);
	assert(valid.validate_inputUI_user("4") == true);

	assert(valid.validate_inputUI_user("5") == false);
	assert(valid.validate_inputUI_user("11") == false);
	assert(valid.validate_inputUI_user("6") == false);
	assert(valid.validate_inputUI_user("") == false);
	assert(valid.validate_inputUI_user("input") == false);
}


void TestValidation::Testvalidate_inputUI_admin() {
	assert(valid.validate_inputUI_admin("1") == true);
	assert(valid.validate_inputUI_admin("2") == true);
	assert(valid.validate_inputUI_admin("3") == true);
	assert(valid.validate_inputUI_admin("4") == true);
	assert(valid.validate_inputUI_admin("5") == true);

	assert(valid.validate_inputUI_admin("6") == false);
	assert(valid.validate_inputUI_admin("7") == false);
	assert(valid.validate_inputUI_admin("22") == false);
	assert(valid.validate_inputUI_admin("") == false);
	assert(valid.validate_inputUI_admin("input") == false);
}


void TestValidation::Testvalidate_inputUI_3() {
	assert(valid.validate_inputUI_3("1") == true);
	assert(valid.validate_inputUI_3("2") == true);
	assert(valid.validate_inputUI_3("3") == true);

	assert(valid.validate_inputUI_3("5") == false);
	assert(valid.validate_inputUI_3("33") == false);
	assert(valid.validate_inputUI_3("6") == false);
	assert(valid.validate_inputUI_3("") == false);
	assert(valid.validate_inputUI_user("input") == false);
}


void TestValidation::Testvalidate_inputUi_number() {
	assert(valid.validate_inputUi_number("5") == true);
	assert(valid.validate_inputUi_number("33") == true);
	assert(valid.validate_inputUi_number("6") == true);
	assert(valid.validate_inputUi_number("2000") == true);
	assert(valid.validate_inputUi_number("0") == true);

	assert(valid.validate_inputUi_number("asa nu") == false);
	assert(valid.validate_inputUi_number("nu merge nu merge") == false);
	assert(valid.validate_inputUi_number("eiei") == false);
	assert(valid.validate_inputUi_number("") == false);
}


void TestValidation::Testvalidate_inputUi_jahr() {
	assert(valid.validate_inputUi_jahr(100) == true);
	assert(valid.validate_inputUi_jahr(2015) == true);
	assert(valid.validate_inputUi_jahr(2020) == true);
	assert(valid.validate_inputUi_jahr(2019) == true);
	assert(valid.validate_inputUi_jahr(2018) == true);

	assert(valid.validate_inputUi_jahr(2021) == false);
	assert(valid.validate_inputUi_jahr(3413413) == false);
	assert(valid.validate_inputUi_jahr(2022) == false);
	assert(valid.validate_inputUi_jahr(30000) == false);
	assert(valid.validate_inputUi_jahr(-3242) == false);
}


void TestValidation::TestvalidateCycle() {
	
}


void TestValidation::TestBadInput() {
	BadInput bad0;
	std::string x = bad0.what();
	assert(x == "Bad input");
	BadInput bad1("inputUI");
	x = bad1.what();
	assert(x == "\nInput was not correct, please choose between 0, 1 and 2\n");
	BadInput bad2("inputUI_user");
	x = bad2.what();
	assert(x == "\nInput was not correct, please choose between 1, 2, 3 and 4\n");
	BadInput bad3("inputUI_3");
	x = bad3.what();
	assert(x == "\nInput was not correct, please choose between  1, 2, and 3\n");
	BadInput bad4("inputUI_admin");
	x = bad4.what();
	assert(x == "\nInput was not correct, please choose between 1, 2, 3, 4 and  5\n");
	BadInput bad5("titel");
	x = bad5.what();
	assert(x == "\nInput was not correct, please choose a non numeric name\n");
	BadInput bad6("genre");
	x = bad6.what();
	assert(x == "\nInput was not correct, please choose a non numeric genre\n");
	BadInput bad7("jahr");
	x = bad7.what();
	assert(x == "\nInput was not correct, please choose a correct number between 0 and 2020\n");
	BadInput bad8("likes");
	x = bad8.what();
	assert(x == "\nInput was not correct, please choose a number for likes\n");
	BadInput bad9("trailer");
	x = bad9.what();
	assert(x == "\nInput was not correct, please choose a correct url\n");
}


void TestValidation::testAll() {
	std::cout << "\nTest Validation\n";
	Testvalidate_inputUI();
	Testvalidate_inputUI_user();
	Testvalidate_inputUI_admin();
	Testvalidate_inputUI_3();
	Testvalidate_inputUi_number();
	Testvalidate_inputUi_jahr();
	TestvalidateCycle();
	TestBadInput();
	std::cout << "\n";
}