#include "Movie.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;    

int main(){
    string name, genre, director;
    int year, boxOffice, duration, choice, counter;
    double rating;
    vector<Movie> movieList;


    ifstream fin("movie.txt");
    if (!fin) {
        cout << "Can't open the file" << endl;
        return 1;
    }
    while (fin >> name >> genre >> director >> year >> boxOffice >> duration >> rating) {
        ReadFromFile(name,genre, director,year,boxOffice,duration,rating, movieList);
    }
    fin.close();
    
        do {
        cout << "┌──────────────────MAIN MENU────────────────────┐" << endl;
        cout << "|1. Print All Films and Statistics              |" << endl;
        cout << "|2. Print Information by film                   |" << endl;
        cout << "|3. Print Information by Director               |" << endl;
        cout << "|4. Update Information about film               |" << endl;
        cout << "|5. Insert New Film                             |" << endl;
        cout << "|6. Save to File                                |" << endl;
        cout << "|0. Exit from the Program                       |" << endl;
        cout << "|───────────────────────────────────────────────|" << endl;
        cout << "|Please enter your selection (number only): ";

        choice = GetValidatedInt();
        switch (choice) {
        case 1:
            cout << "You entered: " << choice << endl;
            PrintLabels();
            for (int i = 0; i < movieList.size(); i++) {
                movieList[i].PrintAllMovie();
            }
            break;
        case 2:
            cout << "You entered: " << choice << endl;
            Movie::PrintByFilm(movieList);
            break;
        case 3:
            cout << "You entered: " << choice << endl;
            Movie::PrintByDirector(movieList);
            break;
        case 4:
            cout <<"You entered: " << choice << endl;
            Movie::UpdateInfoFilm(movieList);
            break;
        case 5:
            cout <<"You entered: " << choice << endl;
            Movie::InsertNewFilm(movieList);
            break;
        case 6:
            cout <<"You entered: " << choice << endl;
            Movie::SaveToFile(movieList);
            break;
        case 0:
            cout << "You entered: " << choice << endl;
            cout << "Thanks for using our Program. Have a great day!" << endl;
            break;
        default:
            cout << "You entered: " << choice << "\n";
            cout << "That menu item doesn't exist, try again." << endl;
            break;
            }
        } while (choice != 0);
    return 0;
}
