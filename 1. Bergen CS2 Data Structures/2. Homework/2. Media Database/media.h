#pragma once

#include <movie.h>

#include <iostream>

namespace media
{
    class MediaClass
    {
        public:
            // Getters
            std::string getMediaId();
            std::string getMediaTitle();
            int getMediaYear();

            // Setters
            void setMediaID(std::string);
            void setMediaTitle(std::string);
            void setMediaYear(int);

        private:
            std::string _mediaID;
            std::string _mediaTitle;
            int _mediaYear;
    };
}