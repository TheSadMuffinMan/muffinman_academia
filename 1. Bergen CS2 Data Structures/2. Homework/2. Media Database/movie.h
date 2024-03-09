#pragma once

#include <media.h>
#include <iostream>

namespace movieNamespace
{
    class MovieClass: public media::MediaClass
    {
        public:
            // Initializes all values to nullptr.
            MovieClass();
            ~MovieClass();

            // void DisplayInfo(); // This function does not need to be defined here.

            // Native Getters
            float getRating();
            std::string getDirector();

            // Native Setters
            void setRating(float);
            void setRating(std::string);
            void setDirector(std::string);

        private:
            float _rating;
            std::string _director;
    };
}