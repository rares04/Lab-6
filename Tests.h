#pragma once
#include "TestAdmin.h"
#include "TestRepo.h"
#include "TestUser.h"
#include "TestValidation.h"

class Tests {
private:
	TestRepo testRepo;
	TestAdmin testAdmin;
	TestUser testUser;
	TestValidation testValid;
public:
	void testAll();
};

