#include "TestAdmin.h"
#include <cassert>


void TestAdmin::TestaddFilm() {
	admin.addFilm(f1);
	admin.addFilm(f2);
	admin.addFilm(f3);
	admin.addFilm(f4);
	admin.addFilm(f5);
	admin.addFilm(f6);
	admin.addFilm(f7);
	admin.addFilm(f8);
	admin.addFilm(f9);
	admin.addFilm(f10);

	assert(admin.getFilmRepo().getFilme().size() == 10);

	// Checking from each film from the list, that it's the same with the created one
	assert(admin.getFilmRepo().getFilm_byIndex(0) == f1);
	assert(admin.getFilmRepo().getFilm_byIndex(1) == f2);
	assert(admin.getFilmRepo().getFilm_byIndex(2) == f3);
	assert(admin.getFilmRepo().getFilm_byIndex(3) == f4);
	assert(admin.getFilmRepo().getFilm_byIndex(4) == f5);

	// Testing Add - Checking the output of the function when same film will be added
	admin.getFilmRepo().addFilm(f1);
	admin.getFilmRepo().addFilm(f2);
	admin.getFilmRepo().addFilm(f3);
	admin.getFilmRepo().addFilm(f4);
	admin.getFilmRepo().addFilm(f5);
}


void TestAdmin::TestupdateTitel() {
	admin.updateTitel(f6, "New Titel");
	assert(admin.getFilmRepo().getFilm_byIndex(5).getTitel() == "New Titel");
	admin.updateTitel(f7, "New Titel");
	assert(admin.getFilmRepo().getFilm_byIndex(6).getTitel() == "New Titel");
}


void TestAdmin::TestupdateGenre() {
	admin.updateGenre(f8, "New Genre");
	assert(admin.getFilmRepo().getFilm_byIndex(7).getGenre() == "New Genre");
	admin.updateGenre(f9, "New Genre");
	assert(admin.getFilmRepo().getFilm_byIndex(8).getGenre() == "New Genre");
}


void TestAdmin::TestupdateJahr() {
	admin.updateJahr(f8, 3000);
	assert(admin.getFilmRepo().getFilm_byIndex(7).getJahr() == 3000);
	admin.updateJahr(f9, 3000);
	assert(admin.getFilmRepo().getFilm_byIndex(8).getJahr() == 3000);
}


void TestAdmin::TestupdateLikes() {
	admin.updateLikes(f1, 0);
	assert(admin.getFilmRepo().getFilm_byIndex(0).getLikes() == 0);
	admin.updateLikes(f2, 0);
	assert(admin.getFilmRepo().getFilm_byIndex(1).getLikes() == 0);
}


void TestAdmin::TestupdateTrailer() {
	admin.updateTrailer(f3, "New Trailer");
	assert(admin.getFilmRepo().getFilm_byIndex(2).getTrailer() == "New Trailer");
	admin.updateTrailer(f4, "New Trailer");
	assert(admin.getFilmRepo().getFilm_byIndex(3).getTrailer() == "New Trailer");
}


void TestAdmin::TestdeleteFilm() {
	admin.deleteFilm(admin.getFilmRepo().getFilm_byIndex(0));
	admin.deleteFilm(admin.getFilmRepo().getFilm_byIndex(2));
	admin.deleteFilm(admin.getFilmRepo().getFilm_byIndex(3));

	// There should be 2 movies in the list now
	assert(admin.getFilmRepo().getFilme().size() == 7);

	assert(admin.getFilmRepo().getFilm_byIndex(2) == f5);

	// Testing Delete - Checking the output of the function when deleting a non existent movie
	admin.deleteFilm(f1);
	admin.deleteFilm(f3);
	admin.deleteFilm(f5);
}


void TestAdmin::TestgetFilmRepo() {
	std::vector<Film> test_liste;
	test_liste.push_back(f1);
	test_liste.push_back(f2);
	test_liste.push_back(f3);
	test_liste.push_back(f4);
	test_liste.push_back(f5);
	test_liste.push_back(f6);
	test_liste.push_back(f7);
	test_liste.push_back(f8);
	test_liste.push_back(f9);
	test_liste.push_back(f10);

	assert(admin.getFilmRepo().getFilme() == test_liste);
}

void TestAdmin::TestAll() {
	std::cout << "\nTest Administrator\n";
	TestaddFilm();
	TestgetFilmRepo();
	TestupdateTitel();
	TestupdateGenre();
	TestupdateJahr();
	TestupdateLikes();
	TestupdateTrailer();
	TestdeleteFilm();
}