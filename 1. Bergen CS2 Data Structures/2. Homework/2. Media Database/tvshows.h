#pragma once

#include "media.h"
#include "iostream"
#include "sstream"

namespace tvShowNamespace
{
    class TVShowClass: public media::MediaClass
    {
        public:

            // Default constructor/destructor.

            TVShowClass();
            ~TVShowClass();


            // Virtual inherited function.
            void displayInfo();


            // Native Getters

            float getRating();
            int getNumEpisodes();


            // Native Setters

            void setRating(float);
            void setRating(std::string); // Special overloaded function.
            void setNumEpisodes(int);
            void setNumEpisodes(std::string); // Special overloaded function.

        private:
            float _rating;
            int _numEpisodes;
    };
}