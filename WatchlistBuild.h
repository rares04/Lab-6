#pragma once
#include <vector>
#include <string>
#include "Film.h"
#include "FilmRepository.h"
#include <fstream>
using namespace std;

class WatchlistBuild
{
public:

    virtual void build_watchlist(vector <Film> watchlist, FilmRepository repo);
    void copy_line_by_line_from_and_store_into(string source, string destination);
};
