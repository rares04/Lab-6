#pragma once
#include "Validation.h"

class TestValidation {
private:
	Validation valid;

	// Tests the function that Validates input from the main page
	void Testvalidate_inputUI();

	// Tests the function that Validates input for user Actions
	void Testvalidate_inputUI_user();

	// Tests the function that Validates input for admin Actions
	void Testvalidate_inputUI_admin();

	// Tests the function that Validates input for User Action 1
	void Testvalidate_inputUI_3();

	// Tests the function that Validates input for numbers
	void Testvalidate_inputUi_number();

	// Tests the function that Validates input for jahr
	void Testvalidate_inputUi_jahr();

	// Tests the function that uses all the functions from Validation c;ass
	void TestvalidateCycle();
public:
	void testAll();
};

