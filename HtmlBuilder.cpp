#include "HtmlBuilder.h"
#include <fstream>

using namespace std;

void HtmlBuilder::build_watchlist(vector <Film> watchlist, FilmRepository repo)
{
    string filename = "watchlist.html";
    ofstream fin;
    fin.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

    copy_line_by_line_from_and_store_into("header.html", filename);

    for (int i = 0; i < watchlist.size(); i++)
    {
        Film film = repo.getFilm_byMatch(watchlist[i]);
        fin << "<tr><th scope = 'row'>" << "</th><td><strong>" << film.getTitel() << "</strong></td><td>" << film.getGenre() << "<td>" << film.getJahr() << "</td><td>" << film.getLikes() << "</td><td><a href=\"https://" << film.getTrailer()<< "\" target='_blank'>Click link!</a></td></tr>" << '\n';
    }

    ifstream file("footer.html");
    string str;
    while (getline(file, str))
        fin << str << '\n';
}