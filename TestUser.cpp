#include "TestUser.h"
#include <cassert>


void TestUser::TestgetWatchList() {
    std::vector<Film> test_watchlist;
    test_watchlist.push_back(f1);
    test_watchlist.push_back(f2);
    test_watchlist.push_back(f3);
    test_watchlist.push_back(f4);
    test_watchlist.push_back(f5);

    assert(test_watchlist == user.getWatchList());
}


void TestUser::TestsetWatchList() {
    std::vector<Film> test_watchlist;
    test_watchlist.push_back(f1);
    test_watchlist.push_back(f2);
    test_watchlist.push_back(f3);
    test_watchlist.push_back(f4);

    // Setting the watchlist to have only the first 4 movies instead of all 5
    user.setWatchList(test_watchlist);
    assert(user.getWatchList() == test_watchlist);
}


void TestUser::TestaddFilmToWatchList() {
    // Test add, adding 5 movies to the watchlist
    user.addFilmToWatchList(f1);
    user.addFilmToWatchList(f2);
    user.addFilmToWatchList(f3);
    user.addFilmToWatchList(f4);
    user.addFilmToWatchList(f5);

    // Size should be 5
    assert(user.getWatchList().size() == 5);

    // Adding same movies to check what happens
    user.addFilmToWatchList(f1);
    user.addFilmToWatchList(f2);
    user.addFilmToWatchList(f3);
    user.addFilmToWatchList(f4);
    user.addFilmToWatchList(f5);
}


void TestUser::TestremoveFilmFromWatchList() {
    user.removeFilmFromWatchList(f1);
    user.removeFilmFromWatchList(f2);
    user.removeFilmFromWatchList(f3);

    // Size should be 1 now
    assert(user.getWatchList().size() == 1);

    // Trying to delete a non-existent movie
    user.removeFilmFromWatchList(f1);
    user.removeFilmFromWatchList(f2);
    user.removeFilmFromWatchList(f3);
}


void TestUser::Testlike() {
    FilmRepository test_filmrepo;
    test_filmrepo.addFilm(f1);
    test_filmrepo.addFilm(f2);
    test_filmrepo.addFilm(f3);
    test_filmrepo.addFilm(f4);

    user.getFilmRepo() = test_filmrepo;

    // the only remaining movie in the watchlist is movie 4, because the others were deleted
    double old_likes = user.getWatchList()[0].getLikes();
    user.like(f4);
    assert(user.getFilmRepo().getFilme()[3].getLikes() == old_likes + 1);
}


void TestUser::Testsearch_film() {
    // Adding the rest of the films back to the watchlist, 5 will not be added
    user.addFilmToWatchList(f1);
    user.addFilmToWatchList(f2);
    user.addFilmToWatchList(f3);

    assert(user.search_film(f1) == true);
    assert(user.search_film(f2) == true);
    assert(user.search_film(f3) == true);
    assert(user.search_film(f5) == false);
}


void TestUser::TestgetFilmRepo() {
    FilmRepository test_filmrepo;
    test_filmrepo.addFilm(f1);
    test_filmrepo.addFilm(f2);

    user.getFilmRepo() = test_filmrepo;

    assert(user.getFilmRepo().getFilme() == test_filmrepo.getFilme());
}


void TestUser::TestAll(){
    cout << "\nTest User\n";
    TestaddFilmToWatchList();
    TestgetWatchList();
    TestsetWatchList();
    TestremoveFilmFromWatchList();
    Testlike();
    Testsearch_film();
    TestgetFilmRepo();
    cout << "\n\n";
}