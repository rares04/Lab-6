#pragma once
#include "Film.h"
#include <vector>
#include "FilmRepository.h"

using std::vector;

class TestRepo {
private:
	FilmRepository repo;

	Film f1{ "The Platform", "Thriller", 2019, 76190, "https://www.youtube.com/watch?v=RlfooqeZcdY" };
	Film f2{ "The Maze Runner", "Action", 2014, 401481, "https://www.youtube.com/watch?v=AwwbhhjQ9Xk" };
	Film f3{ "Zodiac", "Crime", 2007, 424385, "https://www.youtube.com/watch?v=yNncHPl1UXg" };
	Film f4{ "Shutter Island", "Mystery", 2010, 1065137, "https://www.youtube.com/watch?v=5iaYLCiq5RM" };
	Film f5{ "Se7en", "Crime", 1995, 1364614, "https://www.youtube.com/watch?v=znmZoVkCjpI" };
	Film f6{ "Inception", "Action", 2010, 5, "https://www.youtube.com/watch?v=YoHD9XEInc0" };
	Film f7{ "Joker", "Drama", 2019, 9, "https://www.youtube.com/watch?v=rgXplohCw5o" };
	Film f8{ "Avengers: Endgame", "Action", 2019, 15, "https://www.youtube.com/watch?v=TcMBFSGVi1c" };
	Film f9{ "The Wolf of Wall Street", "Biography", 2013, 7, "https://www.youtube.com/watch?v=iszwuX1AK6A" };
	Film f10{ "Suicide Squad", "Action", 2016, 9, "https://www.youtube.com/watch?v=CmRih_VtVAs" };

	// Tests function that Adds a Film in the list of movies
	void TestaddFilm();

	// Tests function that Updates the Titel of a movie with the given one
	void TestupdateTitel();

	// Tests function that Updates the Genre of a movie with the given one
	void TestupdateGenre();

	// Tests function that Updates the Jahr of a movie with the given one
	void TestupdateJahr();

	// Tests function that Updates the Number of Likes of a movie with the given one
	void TestupdateLikes();

	// Tests function that Updates the Trailer of a movie with the given one
	void TestupdateTrailer();

	// Tests function that Deletes a Film from the list of movies
	void TestdeleteFilm();

	// Tests function that Returns the list of movies
	void TestgetFilme();

	// Tests function that Returns a movie at a specified index in the list
	void TestgetFilm_byIndex();

	// Tests function that Returns a movie at a specified index in the list
	void TestgetFilm_byMatch();

	// Tests function that Shows the list of movies by genre
	void TestgetFilme_byGenre();

	// Tests function that Returns Number of Likes
	void TestgetLikes();

	// Tests function that saves the movies to a file
	void TestWrite_movies_to_file();

	// Tests function that reads the movies from a file
	void TestRead_movies_to_file();
public:
	// Calls all above listed functions
	void testAll();
};

