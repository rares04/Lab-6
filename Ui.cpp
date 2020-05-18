#include "Ui.h"
#include "Administrator.h"
#include <iostream>
#include <algorithm>
#include "BadInput.h"
#include "Validation.h"

using namespace std;


Ui::Ui(Administrator _admin, User _user) {
    admin = _admin;
    user = _user;
}


void Ui::ui_main() {
    //Infos for the mode, and selection of the mode
    User utilizator;
    Administrator administrator;
    string mode = "\nSelect Mode\n"
                  "0. For exit"
                  "\n1. For user\n"
                  "2. For admin";

    string input;
    Validation valid;

    while (true) {
        // Getting and Validating the input
        valid.validateCycle(mode, input, "inputUI");

        if (input == "1")
            utilizator = userActions();
        if (input == "2")
            administrator = adminActions();
        if (input == "0")
            break;
    }

    // The programm reaches this point before ending -> write the changes in the file
    this->admin.getFilmRepo().write_movies_to_file("movies.txt");
}

User Ui::userActions(){
    // Infos for admin actions
    // 4 Possible Operations with 4 if statements
    User utilizator = user;
    string userActions = "\nUser Menu\n1. To show and add movies by genre\n"
                         "2. To rate a movie and delete it\n"
                         "3. To show the watchList\n"
                         "4. To close\n";

    string input;
    Validation valid;

    while (true) {
        // Getting and Validating the input
        valid.validateCycle(userActions, input, "inputUI_user");

        if (input == "1")
            utilizator = filmGenre();
        else if (input == "2")
            utilizator = deleteAndRate();
        else if (input == "3")
            utilizator.showWatchList();
        else if(input == "4")
            break;
    }

    return utilizator;
}

User Ui::filmGenre(){
    //3 Possible operations for searching by genre
    string next = "1.add to watchList\n"
                  "2.next\n"
                  "3.close\n";

    string genre = "";
    cout << "\nType Genre:";
    cin >> genre;  // No validation for genre needed, because if movies with the given genre don't exit -> all movies will be shown
    
    // gets all film from the typed genre
    vector <Film> filmeByGenre = user.getFilmRepo().getFilme_byGenre(genre);
    int index = 0;
    if(!filmeByGenre.empty()){
        cout << "\n" << filmeByGenre[index];
        //Opens thr browser with the trailer
        system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());
        string input;
        Validation valid;
        while (true) {
            // Getting and Validating the input
            valid.validateCycle(next, input, "inputUI_3");

            if (input == "1"){  // Adding the film to the watchlist
                std::vector<Film> v = user.getWatchList();
                Film key = filmeByGenre[index];

                // Checks if the movie already exists in the watchlist
                if (std::find(v.begin(), v.end(), key) != v.end()){
                    cout<< "\nIt is already in the watchList\n\n";
                    break;
                }

                user.addFilmToWatchList(filmeByGenre[index]);
                index++;
                cout << "\nMovie was added to your watchlist\nSize of the watchlist: " << user.getWatchList().size() << "\n";
                break;
            }
            else if (input == "2") {  // Goes to the next movie
                if (index == filmeByGenre.size()-1){
                    cout << "\nThere are no more movies with this Genre\n";
                    break;
                }
                index++;
                cout << filmeByGenre[index];
                //Opens the browser with the trailer
                system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());

            }
            else if (input == "3")
                break;
        }
    }
    else {
        cout << "\nNo movie with this Genre exists, a list with all the available movies will appear\n";
        user.getFilmRepo().showFilme();
    }

    return user;
}

User Ui::deleteAndRate(){
    // checks if a film is in the watchlist, and if it is ,then asks the user if he wants to delete it or rate it
    string title;
    cout << "Enter Title to delete: ";
    cin.ignore();  // Taking the correct input, input can be anything, because it will be searched in the list anyway, if not found message will appear
    getline(cin, title);

    std::vector<Film> v = user.getWatchList();
    Film key = Film("", "", 0, 0, "");
    for (size_t i = 0; i < user.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
        if (title == user.getFilmRepo().getFilme()[i].getTitel()) {
            key = user.getFilmRepo().getFilme()[i];
            break;
        }
    }
    if (!(std::find(v.begin(), v.end(), key) != v.end())) {
        cout << "Is not in the watchList\n";
    } else{
        // 3 Possible operations, with 3 if statements
        while(true){
            cout<<"Do you want to rate the film with a like?\n";
            string input;
            string instructions = "1. Yes\n"
                                  "2. Just delete\n"
                                  "3. Cancel\n"
                                  "Input: ";

            Validation valid;
            // Getting and Validating the input
            valid.validateCycle(instructions, input, "inputUI_3");
            if(input == "1") {
                user.like(key);
                admin.updateLikes(key, key.getLikes() + 1);
                user.removeFilmFromWatchList(key);
                break;
            }
            else if (input == "2"){
                user.removeFilmFromWatchList(key);
                break;
            }
            else if(input == "3"){
                break;
            }
        }
    }
    return user;
}

Administrator Ui::adminActions(){
    // infos about the 5 admin operations
    string adminActions = "\n1. To Add a film\n"
                          "2. To remove a film\n"
                          "3. To edit a film\n"
                          "4. To show all films\n"
                          "5. To close\n";
    while (true) {
        string input;
        Validation valid;
        // Getting and Validating the input
        valid.validateCycle(adminActions, input, "inputUI_admin");
        // reads all the film atributes from input and add the film to the repo
        if (input == "1"){
            string title, genre, jahr, likes, trailer;
            
            // Getting and Validating the input
            valid.validateCycle("", title, "titel");

            // Getting and Validating the input
            valid.validateCycle("", genre, "genre");

            // Getting and Validating the input
            valid.validateCycle("", jahr, "jahr");
            
            // Getting and Validating the input
            valid.validateCycle("", likes, "likes");

            // Getting and Validating the input
            valid.validateCycle("", trailer, "trailer");

            double d_jahr = stod(jahr);  // Convert it to type double
            double d_likes = stod(likes);  // Convert it to type double
            Film film = Film(title, genre, d_jahr, d_likes, trailer);
            admin.addFilm(film);
        }
        // Checks if the typed film is in the repository and if it is, deletes it
        else if (input == "2") {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Enter Title to delete: ";
            cin.ignore();  // No need to validate the input, if not found in the repository nothing happens
            getline(cin, title);
            for (size_t i = 0; i < admin.getFilmRepo().getFilme().size(); i++){  // Checking if the film exists
                if (title == admin.getFilmRepo().getFilme()[i].getTitel()) {
                    film = admin.getFilmRepo().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "") {
                cout << "Film not found\n";
            } 
            else {
                admin.deleteFilm(film);
                user.removeFilmFromWatchList(film);
            }

        }// Checks if the film exists, and if it does, edits its attributes
        else if (input == "3"){
            string title;
            Film film = Film("","",0,0,"");
            cout<<"Enter Title to edit: ";cin.ignore(); getline(cin, title);  // No need to validate the input, if not found in the repository nothing happens
            for (size_t i = 0; i < admin.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
                if (title == admin.getFilmRepo().getFilme()[i].getTitel()) {
                    film = admin.getFilmRepo().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "")
                cout << "Film not found\n";
            else
            while (true) {
                string input2;
                //infos for editing a film
                string instrunctions = "\nWhat do you want to edit?\n"
                                       "1. To edit title\n"
                                       "2. To edit genre\n"
                                       "3. To edit jahr\n"
                                       "4. To edit likes\n"
                                       "5. To edit Trailer\n"
                                       "Input: ";

                // Getting and Validating the input
                valid.validateCycle(instrunctions, input2, "inputUI_admin");

                if (input2 == "1") {
                    string title2;
                    // Getting and Validating the input
                    valid.validateCycle("", title2, "titel");

                    admin.updateTitel(film, title2);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setTitel(title2);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "2") {
                    string genre;
                    // Getting and Validating the input
                    valid.validateCycle("", genre, "genre");

                    admin.updateGenre(film, genre);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setGenre(genre);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "3") {
                    string jahr;
                    // Getting and Validating the input
                    valid.validateCycle("", jahr, "jahr");

                    
                    double d_jahr = stod(jahr);
                    admin.updateJahr(film, d_jahr);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setJahr(d_jahr);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "4") {
                    string likes;
                    // Getting and Validating the input
                    valid.validateCycle("", likes, "likes");

                    double d_likes = stod(likes);
                    admin.updateLikes(film, d_likes);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setLikes(d_likes);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "5") {
                    string trailer;
                    // Getting and Validating the input
                    valid.validateCycle("", trailer, "trailer");
                    
                    admin.updateTrailer(film, trailer);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setTrailer(trailer);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
            }
        }// Prints all the films
        else if (input == "4"){
            admin.showFilme();
        }
        else if(input == "5"){
            break;
        }
    }
    return admin;
}
