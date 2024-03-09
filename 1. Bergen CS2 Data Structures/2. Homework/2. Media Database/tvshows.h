#pragma once

#include <tvshows.h>
#include <media.h>
#include <iostream>

namespace tvShows
{
    class TVShow: public media::MediaClass
    {
        public:
            TVShow();
            ~TVShow();

            // virtual DisplayInfo();

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