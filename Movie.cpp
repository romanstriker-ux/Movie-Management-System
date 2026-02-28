#include "Movie.h"
#include <fstream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

// --- (Global Scope) ---

int GetValidatedInt() { // Fuction to get 100% integer
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        } else {
            return value;
        }
    }
}

double GetValidatedDouble() { // Fuction to get 100% double
    double value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        } else {
            return value;
        }
    }
}

void PrintLabels(){  //Prints the labels
    cout << left
         << setw(25) << "Movie"
         << setw(15) << "Genre"
         << setw(25) << "Director"
         << setw(8) << "Year"
         << setw(16) << "Box Office($M)"
         << setw(13) << "Duration(m)"
         << setw(13) << "Rating";
    cout << endl;
    cout << string(105, '=') << endl;
}

void ReadFromFile(string name, string genre, string director, int year, int boxOffice, int duration, double rating, vector<Movie> &movieList){
    Movie m;
    m.SetNameMovie(name);
    m.SetGenre(genre);
    m.SetDirector(director);
    m.SetYear(year);
    m.SetBoxOffice(boxOffice);
    m.SetDuration(duration);
    m.SetRating(rating);
    movieList.push_back(m);
}

// --- (Movie Scope ) ---

Movie::Movie(){
    nameMovie = "Unknown";
    genre = "Unknown";
    director = "Unknown";
    year = 0;
    boxOffice = 0;
    duration = 0;
    rating = 0.0;
}

// setters
void Movie::SetNameMovie(string moviePar){ nameMovie = moviePar; }
void Movie::SetGenre(string genrePar){ genre = genrePar; }
void Movie::SetDirector(string directorPar){ director = directorPar; }
void Movie::SetYear(int yearPar){ year = yearPar; }
void Movie::SetBoxOffice(int BoxOfficePar){ boxOffice = BoxOfficePar; }
void Movie::SetDuration(int durationPar){ duration = durationPar; }
void Movie::SetRating(double ratingPar){ rating = ratingPar; }

// Getters
string Movie::GetNameMovie(){ return nameMovie; }
string Movie::GetGenre(){ return genre; }
string Movie::GetDirector(){ return director; }
int Movie::GetYear(){ return year; }
int Movie::GetBoxOffice(){ return boxOffice; }
int Movie::GetDuration(){ return duration; }
double Movie::GetRating(){ return rating; }

void Movie::PrintAllMovie(){
    cout << left
         << setw(25) << nameMovie
         << setw(15) << genre
         << setw(25) << director
         << setw(8) << year
         << setw(16) << boxOffice
         << setw(13) << duration
         << setw(13) << fixed << setprecision(1) << rating;
    cout << "" << endl;
    cout << string(105, '_') << endl;

}

void Movie::PrintByFilm(vector<Movie>& movieList){
    int choice = 0;
    bool done;
    do{
        for(int i = 0; i < movieList.size(); i++) {
            cout << i + 1 << ": " << movieList[i].GetNameMovie() << endl;
        }
        cout << "0: Exit to Main Menu" << endl;
        cout << "Enter the Film Number (or 0 to return): ";
        choice = GetValidatedInt();
        if(choice == 0){
            done = true;
            break;
        }
        if(choice >= 1 && choice <= movieList.size()){
            PrintLabels();
            movieList[choice-1].PrintAllMovie();
            done = true;
        }
        else{
            cout << "You entered: " << choice << endl;
            cout << "That menu item doesn't exist, try again." << endl;
            done = false;
        }
    }while(done != true);
}

void Movie::PrintByDirector(vector<Movie>& movieList){
    int choice = 0;
    bool done;
    string uniqueDirectorName;
    vector<string> uniqueDirectorList;
    for(int i = 0; i < movieList.size(); i++){
        uniqueDirectorName = movieList[i].GetDirector();
        bool alreadyExists = false;
        for(int u = 0; u < uniqueDirectorList.size(); u++){
            if(uniqueDirectorList[u] == uniqueDirectorName){
                alreadyExists = true;
                break;
            }
        }
        if(!alreadyExists){
            uniqueDirectorList.push_back(uniqueDirectorName);
        }
    }
    do{
        for(int i = 0; i < uniqueDirectorList.size(); i++){
            cout << i + 1 << ": " << uniqueDirectorList[i] << endl;
        }
        cout << "0: Exit to Main Menu" << endl;
        cout << "Enter the Director Number (or 0 to return): ";
        choice = GetValidatedInt();
        if(choice == 0){
            done = true;
            break;
        }
        else if(choice >= 1 && choice <= uniqueDirectorList.size()){
            PrintLabels();
            for(int i = 0; i < movieList.size(); i++){
                if(movieList[i].GetDirector() == uniqueDirectorList[choice-1]){
                    movieList[i].PrintAllMovie();
                }
            }
            done = true;
        }
        else{
            cout << "You entered: " << choice << endl;
            cout << "That menu item doesn't exist, try again." << endl;
            done = false;
        }
    }while(done != true);
}

void Movie::UpdateInfoFilm(vector<Movie>& movieList){
    int choice = 0;
    int choiceStat = 0;
    string name, genre, director;
    int year, boxOffice, duration;
    double rating;
    for (int i = 0; i < movieList.size(); i++) {
        cout << i + 1 << ": " << movieList[i].GetNameMovie() << endl;
        }
    cout << "Enter the Film Number: ";
    choice = GetValidatedInt();
    if (choice >= 0 && choice <= movieList.size()){
        PrintLabels();
        movieList[choice-1].PrintAllMovie();
        cout << "Select what you want to update" << endl;
        cout << "1. Movie name" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Director" << endl;
        cout << "4. Year" << endl;
        cout << "5. Box office" << endl;
        cout << "6. Duration" << endl;
        cout << "7. Rating" << endl;
        cout << "Enter: ";
        choiceStat = GetValidatedInt();
        switch (choiceStat) {
            case 1:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter the Movie name(Use '_' instead space): ";
                cin >> name;
                movieList[choice-1].SetNameMovie(name);
                break;
            case 2:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter genre: ";
                cin >> genre;
                movieList[choice-1].SetGenre(genre);
                break;
            case 3:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter director(Use '_' instead space): ";
                cin >> director;
                movieList[choice-1].SetDirector(director);
                break;
            case 4:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter year: ";
                cin >> year;
                movieList[choice-1].SetYear(year);
                break;
            case 5:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter Box Office(1 million = 1): ";
                cin >> boxOffice;
                movieList[choice-1].SetBoxOffice(boxOffice);
                break;
            case 6:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter duration(Only minutes): ";
                cin >> duration;
                movieList[choice-1].SetDuration(duration);
                break;
            case 7:
                cout << "You entered " << choiceStat << endl;
                cout << "Enter rating(One digit after coma): ";
                cin >> rating;
                movieList[choice-1].SetRating(rating);
                break;
            default:
                cout << "You entered: " << choiceStat << endl;
                cout << "That menu item doesn't exist, try again." << endl;
                break;
        }
    }
    else{
        cout << "Out of Range" << endl;
    }
}

void Movie::InsertNewFilm(vector<Movie>& movieList){
    string name, genre, director;
    int year, boxOffice, duration;
    double rating;
    Movie m;

    cout << "Enter the movie name(Use '_' instead space): ";
    cin >> name;
    m.SetNameMovie(name);
    cout << "Enter the genre: ";
    cin >> genre;
    m.SetGenre(genre);
    cout << "Enter director name(Use '_' instead space): ";
    cin >> director;
    m.SetDirector(director);
    cout << "Enter movie year: ";
    year = GetValidatedInt();
    m.SetYear(year);
    cout << "Enter box office(1 million = 1): ";
    boxOffice = GetValidatedInt();
    m.SetBoxOffice(boxOffice);
    cout << "Enter duration(Only minutes): ";
    duration = GetValidatedInt();
    m.SetDuration(duration);
    cout << "Enter rating(One digit after coma): ";
    rating = GetValidatedDouble();
    m.SetRating(rating);
    movieList.push_back(m);
}

void Movie::SaveToFile(vector<Movie>& movieList){
    ofstream fout("outMovie.txt");
    for (int i = 0; i < movieList.size(); i++) {
        fout << movieList[i].GetNameMovie() << " "
             << movieList[i].GetGenre() << " "
             << movieList[i].GetDirector() << " "
             << movieList[i].GetYear() << " "
             << movieList[i].GetBoxOffice() << " "
             << movieList[i].GetDuration() << " "
             << movieList[i].GetRating() << endl;
    }
    cout << "Movies saved to file" << endl;
}
