#include "TestRepo.h"
#include <cassert>

using std::cout;


void TestRepo::TestaddFilm() {
	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
	repo.addFilm(f6);
	repo.addFilm(f7);
	repo.addFilm(f8);
	repo.addFilm(f9);
	repo.addFilm(f10);

	// There should be 5 movies in the list now
	assert(repo.getFilme().size() == 10);

	// Checking from each film from the list, that it's the same with the created one
	assert(repo.getFilm_byIndex(0) == f1);
	assert(repo.getFilm_byIndex(1) == f2);
	assert(repo.getFilm_byIndex(2) == f3);
	assert(repo.getFilm_byIndex(3) == f4);
	assert(repo.getFilm_byIndex(4) == f5);

	// Testing Add - Checking the output of the function when same film will be added
	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
}



void TestRepo::TestupdateTitel() {
	repo.updateTitel(f6, "New Titel");
	assert(repo.getFilm_byIndex(5).getTitel() == "New Titel");
	repo.updateTitel(f7, "New Titel");
	assert(repo.getFilm_byIndex(6).getTitel() == "New Titel");
}


void TestRepo::TestupdateGenre() {
	repo.updateGenre(f8, "New Genre");
	assert(repo.getFilm_byIndex(7).getGenre() == "New Genre");
	repo.updateGenre(f9, "New Genre");
	assert(repo.getFilm_byIndex(8).getGenre() == "New Genre");
}


void TestRepo::TestupdateJahr() {
	repo.updateJahr(f8, 3000);
	assert(repo.getFilm_byIndex(7).getJahr() == 3000);
	repo.updateJahr(f9, 3000);
	assert(repo.getFilm_byIndex(8).getJahr() == 3000);
}


void TestRepo::TestupdateLikes() {
	repo.updateLikes(f1, 0);
	assert(repo.getFilm_byIndex(0).getLikes() == 0);
	repo.updateLikes(f2, 0);
	assert(repo.getFilm_byIndex(1).getLikes() == 0);
}


void TestRepo::TestupdateTrailer() {
	repo.updateTrailer(f3, "New Trailer");
	assert(repo.getFilm_byIndex(2).getTrailer() == "New Trailer");
	repo.updateTrailer(f4, "New Trailer");
	assert(repo.getFilm_byIndex(3).getTrailer() == "New Trailer");
}


void TestRepo::TestdeleteFilm() {
	repo.deleteFilm(repo.getFilm_byIndex(0));
	repo.deleteFilm(repo.getFilm_byIndex(2));
	repo.deleteFilm(repo.getFilm_byIndex(3));

	// There should be 2 movies in the list now
	assert(repo.getFilme().size() == 7);

	assert(repo.getFilm_byIndex(2) == f5);

	// Testing Delete - Checking the output of the function when deleting a non existent movie
	repo.deleteFilm(f1);
	repo.deleteFilm(f3);
	repo.deleteFilm(f5);
}


void TestRepo::TestgetFilme()  {
	std::vector<Film> test = repo.getFilme();
	
	// Because we changed this when testing update function
	f2.setLikes(0);
	f7.setTitel("New Titel");
	assert(test[0] == f2 and test[0] != f1);
	assert(test[1] == f7);
}


void TestRepo::TestgetFilm_byIndex()  {
	// Because we already made a lot of changes, set them back 
	repo.getFilme()[0] = f1;
	repo.getFilme()[1] = f2;
	repo.getFilme()[2] = f3;
	
	// Testing if the functions returns te correct movies
	Film test1 = repo.getFilm_byIndex(0);
	Film test2 = repo.getFilm_byIndex(1);
	Film test3 = repo.getFilm_byIndex(2);

	assert(test1 == f1);
	assert(test2 == f2);
	assert(test3 == f3);
}


void TestRepo::TestgetFilm_byMatch()  {
	// Testing if the functions returns te correct movies
	Film test1 = repo.getFilm_byMatch(f1);
	Film test2 = repo.getFilm_byMatch(f2);
	Film test3 = repo.getFilm_byMatch(f3);

	assert(test1 == f1);
	assert(test2 == f2);
	assert(test3 == f3);
}


void TestRepo::TestgetFilme_byGenre()  {
	repo.getFilme().clear();
	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
	repo.addFilm(f6);
	repo.addFilm(f7);
	repo.addFilm(f8);
	repo.addFilm(f9);
	repo.addFilm(f10);


	// Adding all action movies in test list and test the content of the lsit
	std::vector<Film> test = repo.getFilme_byGenre("Action");
	assert(test.size() == 4);
	assert(test[0] == f2);
	assert(test[1] == f6);
	assert(test[2] == f8);
	assert(test[3] == f10);
}


void TestRepo::TestgetLikes()  {
	double likes1 = repo.getLikes(f2);
	assert(likes1 == f2.getLikes() and likes1 == 0);

	double likes2 = repo.getLikes(f1);
	assert(likes2 == f1.getLikes() and likes2 == 76190);

	double likes3 = repo.getLikes(f3);
	assert(likes3 == f3.getLikes() and likes3 == 424385);
}


void TestRepo::TestWrite_movies_to_file() {
	// Adding in an empty repo the 10 movies on which the functions will be tested
	repo.getFilme().clear();
	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
	repo.addFilm(f6);
	repo.addFilm(f7);
	repo.addFilm(f8);
	repo.addFilm(f9);
	repo.addFilm(f10);
	
	string filename = "test_write_movies.txt";
	repo.write_movies_to_file(filename);
}


void TestRepo::TestRead_movies_to_file() {
	repo.getFilme().clear();
	
	string filename = "test_write_movies.txt";
	repo.read_movies_from_file(filename);

	// Writing back what i read to a new file to check the output
	string new_file = "test_read_movies.txt";
	repo.write_movies_to_file(new_file);

	repo.getFilme().clear();
}


void TestRepo::testAll() {
	cout << "Test Repository\n";
	TestWrite_movies_to_file();
	TestRead_movies_to_file();
	TestaddFilm();
	TestupdateTitel();
	TestupdateGenre();
	TestupdateJahr();
	TestupdateLikes();
	TestupdateTrailer();
	TestdeleteFilm();
	TestgetFilme();
	TestgetFilm_byIndex();
	TestgetFilme_byGenre();
	TestgetFilm_byMatch();
	TestgetLikes();
}