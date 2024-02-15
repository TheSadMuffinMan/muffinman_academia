#pragma once

#include <iostream>

namespace movieNamespace
{
    // Put the class in here
    class MovieClass
    {
        public:
            // Getters
            std::string getIMBDTitleID();
            std::string getMovieTitle();
            int getYear();
            std::string getGenre();
            int getRating();
            std::string getDirector();

            // Setters
            void setIMBDTitleID(std::string);
            void getMovieTitle(std::string);
            void setYear(int);
            void setGenre(std::string);
            void setRating(int);
            void setDirector(std::string);

        private:
            std::string _imbdTitleID;
            std::string _movieTitle;
            int _year;
            std::string _genre;
            int _rating;
            std::string _director;
    };
}