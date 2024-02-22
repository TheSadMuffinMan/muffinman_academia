#pragma once

#include <iostream>

namespace movieNamespace
{
    class MovieClass
    {
        public:

            // Initializes all values to nullptr.
            MovieClass();
            
            ~MovieClass();

            // Getters
            std::string getIMBDTitleID();
            std::string getMovieTitle();
            int getYear();
            std::string getGenre();
            float getRating();
            std::string getDirector();

            // Setters
            void setIMBDTitleID(std::string);
            void setMovieTitle(std::string);
            void setYear(int);
            void setGenre(std::string);
            void setRating(float);
            void setDirector(std::string);

        private:
            std::string _imbdTitleID;
            std::string _movieTitle;
            int _year;
            std::string _genre;
            float _rating;
            std::string _director;
    };
}