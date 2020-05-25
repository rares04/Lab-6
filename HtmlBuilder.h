#pragma once
#include "WatchlistBuild.h"
#include <fstream>
using namespace std;

class HtmlBuilder : public WatchlistBuild
{
public:

    void build_watchlist(vector <Film> watchlist, FilmRepository repo);
};