#pragma once
#include "User.h"

class TestUser {
private:
	User user;

    Film f1{ "The Platform", "Thriller", 2019, 76190, "https://www.youtube.com/watch?v=RlfooqeZcdY" };
    Film f2{ "The Maze Runner", "Action", 2014, 401481, "https://www.youtube.com/watch?v=AwwbhhjQ9Xk" };
    Film f3{ "Zodiac", "Crime", 2007, 424385, "https://www.youtube.com/watch?v=yNncHPl1UXg" };
    Film f4{ "Shutter Island", "Mystery", 2010, 1065137, "https://www.youtube.com/watch?v=5iaYLCiq5RM" };
    Film f5{ "Se7en", "Crime", 1995, 1364614, "https://www.youtube.com/watch?v=znmZoVkCjpI" };

    // Tests function that Returns the watchList
    void TestgetWatchList();

    // Tests function that Sets the watchList
    void TestsetWatchList();

    // Tests function that Adds a film to the watchList
    void TestaddFilmToWatchList();

    // Tests function that Removes a film from the watchList
    void TestremoveFilmFromWatchList();

    // Tests function that Adds 1 like to the film
    void Testlike();

    // Tests function that Searches for the film in the watchlist
    void Testsearch_film();

    // Tests function that Returns the adress of the FilmRepository attribute
    void TestgetFilmRepo();
public:
    void TestAll();
};

