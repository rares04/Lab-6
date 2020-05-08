#pragma once
#include <string>
#include <iostream>

using std::string;


class Film {
private:
	string Titel, Genre, Trailer;
	double Jahr, Likes;
public:
	// Constructor
	Film(string, string, double, double, string);

	// Returns Titel
	string getTitel() const;

	// Changes Titel with the given one
	void setTitel(string _titel);
	
	// Returns Genre
	string getGenre() const;

	// Changes Genre with the given one
	void setGenre(string _genre);

	// Returns Trailer
	string getTrailer() const;

	// Changes Trailer with the given one
	void setTrailer(string _trailer);

	// Returns Jahr
	double getJahr() const;
	
	// Changes Jahr with the given one
	void setJahr(double _jahr);

	// Returns Number of Likes
	double getLikes() const;

	// Changes Number of Likes with the given one
	void setLikes(double _likes);

	// Overloading << operator
	friend std::ostream& operator << (std::ostream& out, const Film& f);

	// Checks if two entities of the object are equal
	friend bool operator==(const Film& f1, const Film& f2);
	friend bool operator!=(const Film& f1, const Film& f2);
};

