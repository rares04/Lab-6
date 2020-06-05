#pragma once
#include "Film.h"
#include <vector>


class FilmRepository {
private:
	std::vector <Film> Filme;
public:
	// Adds a Film in the list of movies
	void addFilm(Film);

	// Updates the Titel of a movie with the given one
	void updateTitel(Film, string);

	// Updates the Genre of a movie with the given one
	void updateGenre(Film, string);

	// Updates the Jahr of a movie with the given one
	void updateJahr(Film, double);

	// Updates the Number of Likes of a movie with the given one
	void updateLikes(Film, double);

	// Updates the Trailer of a movie with the given one
	void updateTrailer(Film, string);

	// Deletes a Film from the list of movies
	void deleteFilm(Film);

	// Shows the list of movies
	void showFilme() const;

	// Returns the list of movies
	std::vector<Film>& getFilme();

	// Returns a movie at a specified index in the list
	Film getFilm_byIndex(int index) const;

	// Returns a movie at a specified index in the list
	Film getFilm_byMatch(Film _film) const;

    // Shows the list of movies by genre
    std::vector<Film> getFilme_byGenre(string _genre) const;

    // Returns Number of Likes
    double getLikes(Film _film) const;

	// Saves the data into the file
	void write_movies_to_file(string filename);

	// Reads the movies from the file
	void read_movies_from_file(string filename);
};

