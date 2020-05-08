#include "Film.h"


Film::Film(string _titel, string _genre, double _jahr, double _likes, string _trailer) {
	Titel = _titel;
	Genre = _genre;
	Jahr = _jahr;
	Likes = _likes;
	Trailer = _trailer;
}


string Film::getTitel() const {
	return Titel;
}


void Film::setTitel(string _titel) {
	Titel = _titel;
}


string Film::getGenre() const {
	return Genre;
}


void Film::setGenre(string _genre) {
	Genre = _genre;
}


string Film::getTrailer() const {
	return Trailer;
}


void Film::setTrailer(string _trailer) {
	Trailer = _trailer;
}


double Film::getJahr() const {
	return Jahr;
}


void Film::setJahr(double _jahr) {
	Jahr = _jahr;
}


double Film::getLikes() const {
	return Likes;
}


void Film::setLikes(double _likes) {
	Likes = _likes;
}


std::ostream& operator << (std::ostream& out, const Film& f) {
	// Reine output Methode no need to be tested
	out << "Film:\n\tTitel: " << f.Titel;
	out << "\n\tGenre: " << f.Genre;
	out << "\n\tJahr: " << f.Jahr;
	out << "\n\tLikes: " << f.Likes;
	out << "\n\tTrailer: " << f.Trailer;
	out << "\n";
	return out;
}


bool operator==(const Film& f1, const Film& f2) {
	return (f1.Titel == f2.Titel && f1.Genre == f2.Genre && f1.Jahr == f2.Jahr && f1.Likes == f2.Likes && f1.Trailer == f2.Trailer);
}


bool operator!=(const Film& f1, const Film& f2) {
	return !(f1 == f2);
}
