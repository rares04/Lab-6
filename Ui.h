#pragma once
#include "User.h"
#include "Administrator.h"
#include <vector>
#include "Validation.h"


class Ui {

private:
    vector <User> userList;
    Administrator admin;
    User user;
public:
    // Contructor, the Admin and User mode will be passed as parameters
    Ui(Administrator _admin, User _user);

    // Main menu, 2 options available, admin mode and user mode
    void ui_main();

    // User Mode
    User userActions();

    // Admin Mode
    Administrator adminActions();

    // Shows all films with the given genre, user can add to watchlist, skip or close
    User filmGenre();

    // User can delete or rate a movie
    User deleteAndRate();
};