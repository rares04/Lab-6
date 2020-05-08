#pragma once
#include<iostream>
#include <vector>
#include "Film.h"
#include "FilmRepository.h"

using namespace std;

class User {
private:
    vector <Film> watchList;
    FilmRepository filmRepo;
public:
    // Default constructor, nothing will be initialized, made to pass User as attribute in UI
    User();

    User(FilmRepository FilmRepo);

    // Return the watchList
    std::vector <Film>& getWatchList();

    // Sets the watchList
    void setWatchList(vector <Film> list) ;

    // Adds a film to the watchList
    void addFilmToWatchList(Film _film);

    // Removes a film from the watchList
    void removeFilmFromWatchList(Film _film);

    // Prints the watchList
    void showWatchList() const;

    // Adds 1 like to the film
    void like(Film _film);

    // Searches for the film in the watchlist
    bool search_film(Film _film) const;

    // Returns the adress of the FilmRepository attribute
    FilmRepository& getFilmRepo();
};