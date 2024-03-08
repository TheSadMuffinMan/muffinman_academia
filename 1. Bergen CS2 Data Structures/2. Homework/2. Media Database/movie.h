#pragma once

#include <media.h>

#include <iostream>
#include <string>
#include <sstream>

namespace movieNamespace
{
    class MovieClass: public media::MediaClass
    {
        public:

            // Initializes all values to nullptr.
            MovieClass();
            ~MovieClass();

            // Native Getters
            std::string getGenre();
            float getRating();
            std::string getDirector();

            // Native Setters
            void setGenre(std::string);
            void setRating(float);
            void setRating(std::string);
            void setDirector(std::string);

        private:
            std::string _genre;
            float _rating;
            std::string _director;
    };
}