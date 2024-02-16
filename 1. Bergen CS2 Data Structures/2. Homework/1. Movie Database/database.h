#pragma once
#include <iostream>
#include "movie.h"

// The database should have the following variables: name, db_id, array for Movies (as pointers)
// Functionality: Add movie, remove movie (given ID), display all movies, search for movie given title or genre
// and print out a table of them.
class Database
{
    public:
        //

    private:
        std::string name;
        int db_id;
        int movieListSize;
        movieNamespace::MovieClass* movieListArray[];
};