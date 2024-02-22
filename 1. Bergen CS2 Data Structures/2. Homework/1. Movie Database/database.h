#pragma once
#include <iostream>
#include "movie.h"

// The database should have the following variables: name, db_id, array for Movies (as pointers)
// Functionality: Add movie, remove movie (given ID), display all movies, search for movie given title or genre
// and print out a table of them.
class Database
{
    public:
        // Default contstructor and destructor.
        Database();
        Database(std::string, int);
        ~Database();

        // Main methods
        void loadData();
        void displayAllMovies();
        void addMovie();
        void removeMovie();
        void searchFunction();
        void objectCounterIterator();

        // Getters
        std::string getName();
        int getDb_id();
        std::size_t getObjectCounter();
        movieNamespace::MovieClass* getMovieListArrayAtPosition(std::size_t);

        // Setters
        void setName(std::string);
        void setDb_id(int);
        void setObjectCounter(std::size_t);
        void setMovieListArray(movieNamespace::MovieClass*, std::size_t);

    private:
        std::string _name;
        int _db_id;
        std::size_t _objectCounter;
        movieNamespace::MovieClass* _movieListArray[10];
};