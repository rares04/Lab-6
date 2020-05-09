#include "Tests.h"

void Tests::testAll() {
	testRepo.testAll();
	testAdmin.TestAll();
	testUser.TestAll();
	testValid.testAll();
	std::cout << "\nTests done!!\n\n";
}