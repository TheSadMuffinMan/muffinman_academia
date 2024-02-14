#pragma once
#include <iostream>
#include "movie.h"
#include "main.cpp"

// The database should have the following variables: name, db_id, array for Movies (as pointers)

class Database
{
    public:
        //

    private:
        std::string name;
        int db_id;
        // std::size_t movieArraySize = 100;
        movieNamespace::MovieClass* movieListArray[];
};