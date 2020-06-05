#pragma once
#include "FilmRepository.h"
#include "Ui.h"
#include <iostream>
#include "Tests.h"
#include "WatchlistBuild.h"
#include <unordered_map>
#include "HtmlBuilder.h"
#include "CsvBuilder.h"

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
    string filename_watchlist = "watchlist.txt";
    user.read_movies_from_file(filename_watchlist);   // Saving the movies from the watchlist.txt in the watchlist of the user
    Administrator admin = Administrator(filmRepo);

    // Opening the menu
    Ui a(admin, user);
    a.ui_main();
}