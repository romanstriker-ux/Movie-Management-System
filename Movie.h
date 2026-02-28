#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <vector>
#include <string>

// Auxiliary functions (not belonging to the class)
int GetValidatedInt();
double GetValidatedDouble();
void PrintLabels();
void ReadFromFile(std::string name, std::string genre, std::string director, int year, int boxOffice, int duration, double rating, std::vector<class Movie> &movieList);

class Movie {
public:
    // Constructor
    Movie();

    // setters
    void SetNameMovie(std::string moviePar);
    void SetGenre(std::string genrePar);
    void SetDirector(std::string directorPar);
    void SetYear(int yearPar);
    void SetBoxOffice(int BoxOfficePar);
    void SetDuration(int durationPar);
    void SetRating(double ratingPar);

    // Getters
    std::string GetNameMovie();
    std::string GetGenre();
    std::string GetDirector();
    int GetYear();
    int GetBoxOffice();
    int GetDuration();
    double GetRating();

    // Option 1. Prints the movie and their description
    void PrintAllMovie();

    // Option 2. Prints description considering the selected film
    static void PrintByFilm(std::vector<Movie>& movieList);

    // Option 3. Prints description considering the selected director
    static void PrintByDirector(std::vector<Movie>& movieList);

    // Option 4. Function updates one description for chosen film
    static void UpdateInfoFilm(std::vector<Movie>& movieList);

    // Option 5. Function insert new film
    static void InsertNewFilm(std::vector<Movie>& movieList);

    // Function to save to file
    static void SaveToFile(std::vector<Movie>& movieList);

private:
    std::string nameMovie;
    std::string genre;
    std::string director;
    int year;
    int boxOffice;
    int duration;
    double rating;
};

#endif
