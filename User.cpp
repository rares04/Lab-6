#include "User.h"
#include "Film.h"
#include <fstream>

using namespace std;


User::User() {

}


User::User(FilmRepository repo) {
    filmRepo = repo;
}


std::vector<Film>& User::getWatchList() {
    return watchList;
}


void User::setWatchList(vector <Film> _list)  {
    watchList = _list;
}


FilmRepository& User::getFilmRepo() {
    return this->filmRepo;
}


void User::addFilmToWatchList(Film _film) {
    bool found = false;

    for (int i = 0; i < watchList.size() && !found; i++)      // Checking if the film exists in the watchList
        if (_film.getTitel() == watchList[i].getTitel() && _film.getJahr() == watchList[i].getJahr())
            found = true;  // Looping stops, movies was found

    if (found)  // Movies already exists in the list, nothing happens
        cout << "\tFilm " << _film.getTitel() << " existiert schon, nichts wird eingefugt\n";
    else  // Movies does not exist in the list, it will be added to the watchlist
        watchList.push_back(_film);
}


void User::removeFilmFromWatchList(Film _film) {
    bool found = false;
    for (int i = 0; i < watchList.size() && found == false; i++)    // Checking if the film exists in the watchList
        if (_film.getTitel() == watchList[i].getTitel() && _film.getJahr() == watchList[i].getJahr()) {
            found = true;  // Looping stops, movies was found
            watchList.erase(watchList.begin() + i);  // Film be erased form the watchlist
            return;
        }
    // Film was not found, nothing will be erased
    cout << "\tFilm " << _film.getTitel() << " existiert nicht user's watchlist nichts wird geloscht von watchlist\n";
}


void User::showWatchList() const{
    // Shows all movies from the watchlist 
    // It's a pure output method, no need to be tested
    for(int i = 0; i < watchList.size(); i++)
        cout << watchList[i];
}


bool User::search_film(Film _film) const {
    // Function returns true if _film exists in the watchlist
    for (int i = 0; i < watchList.size(); i++)    // Checking if the film exists in the watchList
        if (_film.getTitel() == watchList[i].getTitel() && _film.getJahr() == watchList[i].getJahr())
            return true;
    return false;
}


void User::like(Film _film){
    filmRepo.updateLikes(_film, _film.getLikes() + 1); //adds one like to the film
}


void User::write_movies_to_file(string filename) {
	ofstream fin;
	fin.open(filename, ofstream::out | ofstream::trunc);

	for (size_t i = 0; i < watchList.size(); i++)
		fin << watchList[i].getTitel() << "," << watchList[i].getGenre() << "," << watchList[i].getJahr() << "," << watchList[i].getLikes() << "," << watchList[i].getTrailer() << "\n";

	fin.close();
}


void User::read_movies_from_file(string filename) {
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
		addFilmToWatchList(new_film);
	}
}