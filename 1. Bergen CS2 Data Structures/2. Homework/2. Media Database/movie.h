#pragma once

#include "media.h"
#include "iostream"
#include "sstream"

namespace movieNamespace
{
    class MovieClass: public media::MediaClass
    {
        public:
            // Default constructors and destructors.

            MovieClass();
            ~MovieClass();

            // Virtual inherited function.
            void displayInfo();


            // Native Getters

            float getRating();
            std::string getDirector();


            // Native Setters

            void setRating(float);
            void setRating(std::string); // Special overloaded setter
            void setDirector(std::string);

        private:
            float _rating;
            std::string _director;
    };
}