#pragma once

#include <iostream>

namespace movieNamespace
{
    class MovieClass
    {
        public:
            // Getters
            std::string* getIMBDTitleIDPointer();
            std::string* getMovieTitlePointer();
            int* getYearPointer();
            std::string* getGenrePointer();
            int* getRatingPointer();
            std::string* getDirectorPointer();

            // Setters
            void setIMBDTitleID(std::string*);
            void setMovieTitle(std::string*);
            void setYear(int*);
            void setGenre(std::string*);
            void setRating(int*);
            void setDirector(std::string*);

        private:
            std::string* _imbdTitleID;
            std::string* _movieTitle;
            int* _year;
            std::string* _genre;
            int* _rating;
            std::string* _director;
    };
}