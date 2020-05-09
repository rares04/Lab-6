#include "FilmRepository.h"
#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::ofstream;
using std::ifstream;


void FilmRepository::addFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr())
			found = true;

	if (found == true)  // If the film does exist -> Error message
		cout << "\tFilm " << _film.getTitel() << " existiert schon, nichts wird eingefugt\n";
	else  // If the film does not exist -> Add it
		Filme.push_back(_film);
}


void FilmRepository::updateTitel(Film _film, string _titel) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setTitel(_titel);
			return;
		}
}


void FilmRepository::updateGenre(Film _film, string _genre) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setGenre(_genre);
			return;
		}
}


void FilmRepository::updateJahr(Film _film, double _jahr) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setJahr(_jahr);
			return;
		}
}


void FilmRepository::updateLikes(Film _film, double _likes) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setLikes(_likes);
			return;
		}
}


void FilmRepository::updateTrailer(Film _film, string _trailer) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setTrailer(_trailer);
			return;
		}
}


void FilmRepository::deleteFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Delete
			found = true;
			Filme.erase(Filme.begin() + i);
			return;
		}
	
	// If the film does not exist -> Error message
	if(found == false)
		cout << "\tFilm " << _film.getTitel() << " existiert nicht, nichts wird geloscht\n";
}


void FilmRepository::showFilme() const {
	// Reine output Methode, nichts muss getestet werden -> OpenCppCoverage wird das rot machen
	for (int i = 0; i < Filme.size(); i++)  // Goes trough all the vector and outputs the films (<< Operator wurde uberladen)
		cout << Filme[i];
}


std::vector<Film>& FilmRepository::getFilme() {
	return Filme;
}


Film FilmRepository::getFilm_byIndex(int index) const {
	return Filme[index];
}


Film FilmRepository::getFilm_byMatch(Film _film) const {
	for (int i = 0; i < Filme.size(); i++)   // Searches for the film in the list with movies, return the films if found
		if (Filme[i] == _film)
			return Filme[i];
}


std::vector<Film> FilmRepository::getFilme_byGenre(string _genre) const{
    std::vector <Film> filmByGenre;  // A list with movies that have the specified Genre
    for(int i = 0; i < Filme.size(); i++) {   // Searches for movies with the specified _genre and adds them to a list 
        if (Filme[i].getGenre() == _genre)
            filmByGenre.push_back(Filme[i]);
    }
    return filmByGenre; 
}


double FilmRepository::getLikes(Film _film) const{
    for(int i = 0; i < Filme.size(); i++)  // Searches for the movie given as parameter and returns the number of likes
        if(_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr())
            return _film.getLikes();
    return 0;
}


void FilmRepository::write_movies_to_file(string filename) {
	ofstream fin;
	fin.open(filename, ofstream::out | ofstream::trunc);

	for (size_t i = 0; i < Filme.size(); i++)
		fin << Filme[i].getTitel() << "," << Filme[i].getGenre() << "," << Filme[i].getJahr() << "," << Filme[i].getLikes() << "," << Filme[i].getTrailer() << "\n";

	fin.close();
}


void FilmRepository::read_movies_from_file(string filename) {
	ifstream fout;

	fout.open(filename.c_str());

	char text[1000];
	int index = 0;

	while (!fout.eof()) {
		fout.getline(text, 1000);
		index = 0;
		// We save the text read from the file to the variable line
		string line = text;

		// If the text is empty, then stop
		if (line == "")
			break;
		
		// Saving the titel of the movie
		string titel = "";
		while (line[index] != ',' and index < line.length())
			titel = titel + line[index++];

		// Saving the genre of the movie
		index++;
		string genre = "";
		while (line[index] != ',' and index < line.length())
			genre = genre + line[index++];

		// Saving the year of the movie
		index++;
		string jahr = "";
		while (line[index] != ',' and index < line.length())
			jahr = jahr + line[index++];
		double d_jahr = std::stod(jahr);

		// Saving the number of likes of the movie
		index++;
		string likes = "";
		while (line[index] != ',' and index < line.length())
			likes = likes + line[index++];
		double d_likes = std::stod(likes);

		// Saving the trailer of the movie
		index++;
		string trailer = "";
		while (line[index] != '\n' and index < line.length())
			trailer = trailer + line[index++];

		Film new_film = Film(titel, genre, d_jahr, d_likes, trailer);
		addFilm(new_film);
	}
}