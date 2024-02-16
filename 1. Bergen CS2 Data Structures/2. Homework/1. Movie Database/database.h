#pragma once
#include <iostream>
#include "movie.h"

// The database should have the following variables: name, db_id, array for Movies (as pointers)
// Functionality: Add movie, remove movie (given ID), display all movies, search for movie given title or genre
// and print out a table of them.
class Database
{
    public:
        // Default contstructor and destructor
        Database();
        ~Database();

        // Main methods
        void loadData();
        void displayAllMovies();
        void addMovie();
        void removeMovie();
        void searchFunction();
        std::size_t objectCounterIterator(std::size_t&);

        // Getters
        std::string* getName();
        int* getDb_id();
        std::size_t getObjectCounter();
        // NO GETTER FOR movieListSize;
        // movieNamespace::MovieClass*[] getMovieListArray();

        // Setters
        void setName(std::string*);
        void setDb_id(int*);
        void setObjectCounter(std::size_t);
        void setMovieListSize(std::size_t);
        void setMovieArrayList(movieNamespace::MovieClass movieListArray[], std::size_t, movieNamespace::MovieClass);

    private:
        std::string* _name;
        int* _db_id;
        std::size_t _objectCounter;
        std::size_t _movieListSize;
        movieNamespace::MovieClass* _movieListArray[];
};