#include "CsvBuilder.h"
#include "FilmRepository.h"
#include <fstream>

using namespace std;
void CsvBuilder::build_watchlist(vector <Film> watchlist, FilmRepository repo)
{

    ofstream fin;
    fin.open("watchlist.csv");

    fin << "Titel,Genre,Jahr,Likes,Trailer\n";

    for (int i = 0; i < watchlist.size(); i++)
    {
        Film film = repo.getFilm_byMatch(watchlist[i]);
        fin << film.getTitel() << "," << film.getGenre() << "," << film.getJahr() << "," << film.getLikes() << "," << film.getTrailer() << '\n';
    }

    fin.close();

}