// THIS IS THE BASE CLASS THAT WILL "PRODUCE CHILDREN".
#pragma once

#include <movie.h>
#include <iostream>

namespace media
{
    class MediaClass
    {
        public:
            virtual void displayAllInfo();
            // Getters
            std::string getMediaId();
            std::string getMediaTitle();
            int getMediaYear();
            std::string getGenre();

            // Setters
            void setMediaID(std::string);
            void setMediaTitle(std::string);
            void setMediaYear(int);
            void setGenre(std::string);

        private:
            std::string _mediaID;
            std::string _mediaTitle;
            int _mediaYear;
            std::string _mediaGenre;
    };
}