#pragma once
#include "TestAdmin.h"
#include "TestRepo.h"
#include "TestUser.h"

class Tests {
private:
	TestRepo testRepo;
	TestAdmin testAdmin;
	TestUser testUser;
public:
	void testAll();
};

