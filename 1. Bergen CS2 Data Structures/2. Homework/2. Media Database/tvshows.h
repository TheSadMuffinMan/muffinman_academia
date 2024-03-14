#pragma once

#include <media.h>
#include <iostream>

namespace tvShowNamespace
{
    class TVShowClass: public media::MediaClass
    {
        public:
            TVShowClass();
            ~TVShowClass();

            void displayInfo();

            // Native Getters
            float getRating();
            int getNumEpisodes();

            // Native Setters
            void setRating(float);
            void setRating(std::string);
            void setNumEpisodes(int);
            void setNumEpisodes(std::string);

        private:
            float _rating;
            int _numEpisodes;
    };
}