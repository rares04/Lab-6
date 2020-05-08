#pragma once
#include "FilmRepository.h"


class Administrator {
private:
	FilmRepository FilmRepo;
public:
	Administrator();

    Administrator(FilmRepository FilmRepo);

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

	// Returns the adress of the FilmRepository attribute
	FilmRepository& getFilmRepo();
};

