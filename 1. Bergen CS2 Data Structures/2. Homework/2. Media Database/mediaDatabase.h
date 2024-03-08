#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "movie.h"

// The database should have the following variables: name, db_id, array for Movies (as pointers)
// Functionality: Add movie, remove movie (given ID), display all movies, search for movie given title or genre
// and print out a table of them.
class Database
{
    public:
        // Default contstructor and destructor.
        Database();
        Database(std::size_t, std::string, int);
        ~Database();

        // Main methods
        void loadData(); // Basically Complete, not pulling director.
        void displayAllData(); // Complete, need to come back and "make pretty". <iomanip>
        void displaySingleMovie(movieNamespace::MovieClass*); // Complete.
        void displayAllMovieTitles(); // Complete.
        void addMovie(); // Complete.
        void removeMovie(); // Complete.
        movieNamespace::MovieClass** searchFunction(); // Complete.
        void outputToCSV(movieNamespace::MovieClass*[]); // Complete.
        void objectCounterIterator(); // Complete.

        // Getters
        // std::string getName(); // Never interact with this variable.
        // int getDb_id(); // Never interact with this variable.
        std::size_t getObjectCounter();
        movieNamespace::MovieClass* getMovieListArrayAtPosition(std::size_t);

        // Setters
        void setName(std::string);
        void setDb_id(int);
        void setObjectCounter(std::size_t);
        void setSingleMovieListArray(std::size_t, movieNamespace::MovieClass*);
        // void setEntireMovieListArray(std::size_t, movieNamespace::MovieClass*[]);

    private:
        std::string _name;
        int _db_id;
        std::size_t _objectCounter;
        movieNamespace::MovieClass* _movieListArray[20];
};