#include "User.h"
#include "Film.h"

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
    cout << "\tFilm " << _film.getTitel() << " existiert nicht, nichts wird geloscht\n";
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