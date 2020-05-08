#include "Ui.h"
#include "Administrator.h"
#include <iostream>
#include <algorithm>
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
    string mode = "Select Mode\n"
                  "0. For exit"
                  "\n1. For user\n"
                  "2. For admin";

    string input;
    cout << mode;
    cout << "\nInput: "; cin >> input;
   

    // Validating the input
    Validation valid;
    while (valid.validate_inputUI(input) == false) {
        cout << "\nInput was not correct, please choose between 0, 1 and 2\n" << mode << "\nInput: "; cin >> input;
    }

    while(true) {
        if (input == "1") {
            utilizator = userActions();
            cout << mode;
            cout << "\nInput: "; cin >> input;
        }
        if (input == "2"){
            administrator = adminActions();
            cout << mode;
            cout << "\nInput: "; cin >> input;
        }
        if (input == "0")
            break;
    }

    this->admin.getFilmRepo().write_movies_to_file("movies.txt");
}

User Ui::userActions(){
    // Infos for admin actions
    // 4 Possible Operations with 4 if statements
    User utilizator = user;
    string userActions = "1. To show and add movies by genre\n"
                         "2. To rate a movie and delete it\n"
                         "3. To show the watchList\n"
                         "4. To close\n";
    string input;
    while (true) {
        cout << "User Mode\n";
        cout << "\n" << userActions;
        cout << "\nInput: ";
        cin >> input;

        // Validating the input
        Validation valid;
        while (valid.validate_inputUI_user(input) == false) {
            cout << "\nInput was not correct, please choose between 1, 2, 3 and 4\n" << userActions << "\nInput: "; cin >> input;
        }

        if (input == "1"){
            utilizator = filmGenre();
        }
        else if (input == "2"){
            utilizator = deleteAndRate();
        }
        else if (input == "3"){
            utilizator.showWatchList();
        }
        else if(input == "4"){
            break;
        }
    }

    return utilizator;
}

User Ui::filmGenre(){
    //3 Possible operations for searching by genre
    string next = "1.add to watchList\n"
                  "2.next\n"
                  "3.close\n";

    string genre = "";
    int index = 0;
    cout << "Type Genre:";
    cin >> genre;
    // gets all film from the typed genre
    vector <Film> filmeByGenre = user.getFilmRepo().getFilme_byGenre(genre);
    if(!filmeByGenre.empty()){
        cout << filmeByGenre[index];
        //Opens thr browser with the trailer
        system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());
        while (true) {
            string input;
            cout << next;
            cin >> input;

            // Validating the input
            Validation valid;
            while (valid.validate_inputUI_3(input) == false) {
                cout << "\nInput was not correct, please choose between  1, 2, and 3\n" << next << "\nInput: "; cin >> input;
            }

            if (input == "1"){
                std::vector<Film> v = user.getWatchList();
                Film key = filmeByGenre[index];

                if (std::find(v.begin(), v.end(), key) != v.end()){
                    cout<< "It is already in the watchList\n";
                    break;
                }
                user.addFilmToWatchList(filmeByGenre[index]);
                index++;
                cout << "size: " << user.getWatchList().size() << "\n";
            }
            else if (input == "2") {
                if (index == filmeByGenre.size()-1){
                    cout << "\nThere are no more movies with this Genre\n";
                    break;
                }
                index++;
                cout << filmeByGenre[index];
                //Opens the browser with the trailer
                system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());

            }
            else if (input == "3") {
                break;
            }
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
    cin.ignore();
    getline(cin, title);
    std::vector<Film> v = user.getWatchList();
    Film key = Film("", "", 0, 0, "");
    for (int i = 0; i < user.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
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
            cout << instructions;
            cin >> input;

            // Validating the input
            Validation valid;
            while (valid.validate_inputUI_3(input) == false) {
                cout << "\nInput was not correct, please choose between  1, 2, and 3\n" << instructions  << "\nInput: "; cin >> input;
            }

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
    string adminActions = "1. To Add a film\n"
                          "2. To remove a film\n"
                          "3. To edit a film\n"
                          "4. To show all films\n"
                          "5. To close\n";
    while (true) {
        string input;
        cout << "Admin Mode\n";
        cout << "\n" << adminActions;
        cout << "\nInput: ";
        cin >> input;

        // Validating the input
        Validation valid;
        while (valid.validate_inputUI_admin(input) == false) {
            cout << "\nInput was not correct, please choose between 1, 2, 3, 4 and  5\n" << adminActions << "\nInput: "; cin >> input;
        }
        // reads all the film atributes from input and add the film to the repo
        if (input == "1"){
            string title;
            string genre;
            double jahr;
            double likes;
            string trailer;
            cout<<"Enter Title: "; cin >> title;
            // Validating the input
            Validation valid;
            while (valid.validate_inputUi_number(title) == true) {
                cout << "\nInput was not correct, please choose a non numeric name\n" << "\nEnter Title: "; cin >> title;
            }
            cout<<"Enter Genre: "; cin >> genre;
            // Validating the input
            while (valid.validate_inputUi_number(genre) == true) {
                cout << "\nInput was not correct, please choose a non numeric genre\n" <<"\nEnter Genre: "; cin >> genre;
            }
            cout<<"Enter Jahr: "; cin >> jahr;
            // Validating the input
            while(!cin || valid.validate_inputUi_jahr(jahr) == false) // or if(cin.fail())
            {
                // user didn't input a number
                if(!cin){
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    cout<<"Invalid input\n";
                    cout<<"Enter Jahr: "; cin >> jahr;

                } else if (valid.validate_inputUi_jahr(jahr) == false) {
                    cout << "\nInput was not correct, please choose a correct number\n" << "\nEnter Jahr: "; cin >> jahr;
                }
            }
            cout<<"Enter Likes: "; cin >> likes;
            while(!cin) // or if(cin.fail())
            {
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                cout<<"Invalid input\n";
                cout<<"Enter Likes: "; cin >> likes;
            }
            cout<<"Enter Trailer: "; cin >> trailer;
            // Validating the input
            while (valid.validate_inputUi_number(title) == true) {
                cout << "\nInput was not correct, please choose a correct url\n" << "\nEnter Trailer "; cin >> trailer;
            }
            Film film = Film(title, genre, jahr, likes, trailer);
            admin.addFilm(film);
        }
        // Checks if the typed film is in the repository and if it is, deletes it
        else if (input == "2") {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Enter Title to delete: ";
            cin.ignore();
            getline(cin, title);
            for (int i = 0; i < admin.getFilmRepo().getFilme().size(); i++){  // Checking if the film exists
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
            cout<<"Enter Title to edit: ";cin.ignore(); getline(cin, title);
            for (int i = 0; i < admin.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
                if (title == admin.getFilmRepo().getFilme()[i].getTitel()) {
                    film = admin.getFilmRepo().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "") {
                cout << "Film not found\n";

            }
            while (true) {
                string input2;
                //infos for editing a film
                string instrunctions = "What do you want to edit?\n"
                                       "1. To edit title\n"
                                       "2. To edit genre\n"
                                       "3. To edit jahr\n"
                                       "4. To edit likes\n"
                                       "5. To edit Trailer\n"
                                       "Input: ";
                cout << instrunctions;
                cin >> input2;

                // Validating the input
                while (valid.validate_inputUI_admin(input2) == false) {
                    cout << "\nInput was not correct, please choose between 1, 2, 3, 4 and  5\n" << instrunctions << "\nInput: "; cin >> input;
                }

                if (input2 == "1") {
                    string title2;
                    cout << "New Title: ";
                    cin.ignore();
                    getline(cin, title2);

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
                    cout << "New Genre: ";
                    cin.ignore();
                    getline(cin, genre);

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
                    double jahr;
                    cout << "New Jahr: ";
                    cin >> jahr;
                    while(!cin) // or if(cin.fail())
                    {
                        // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout<<"Invalid input\n";
                        cout<<"New Jahr: "; cin >> jahr;
                    }

                    admin.updateJahr(film, jahr);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setJahr(jahr);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "4") {
                    double likes;
                    cout << "Likes: ";
                    cin >> likes;
                    while(!cin) // or if(cin.fail())
                    {
                        // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout<<"Invalid input\n";
                        cout<<"Likes: "; cin >> likes;
                    }

                    admin.updateLikes(film, likes);
                    // The edit will also be visible if the user has this film added in the watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setLikes(likes);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "5") {
                    string trailer;
                    cout << "New Trailer: ";
                    cin.ignore();
                    getline(cin, trailer);
                    
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
