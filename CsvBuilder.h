#pragma once
#include "WatchlistBuild.h"
#include "FilmRepository.h"

class CsvBuilder : public WatchlistBuild
{
public:
    void build_watchlist(vector <Film> watchlist, FilmRepository repo);
};
