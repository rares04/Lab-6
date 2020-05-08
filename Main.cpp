#include "FilmRepository.h"
#include "Ui.h"
#include <iostream>
#include "Tests.h"
using std::cout;

int main() {
	// Here are all the tests included: TestRepo, TestAdmin and TestUser
	Tests tests;
	tests.testAll();

	// Creating the repository with the movies stored in the file "movies.txt"
	string filename = "movies.txt";
	FilmRepository filmRepo;
	filmRepo.read_movies_from_file(filename);

    User user = User(filmRepo);
    Administrator admin = Administrator(filmRepo);

	// User starts with 3 films in the watchlist
    user.addFilmToWatchList(filmRepo.getFilm_byIndex(0));
    user.addFilmToWatchList(filmRepo.getFilm_byIndex(1));
    user.addFilmToWatchList(filmRepo.getFilm_byIndex(2));
	
	// Opening the menu
	Ui a(admin, user);
	a.ui_main();
}