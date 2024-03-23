// THIS IS THE BASE CLASS THAT WILL "PRODUCE CHILDREN".
#pragma once

#include "iostream"
#include "sstream"

namespace media
{
    class MediaClass
    {
        public:
            virtual void displayInfo();

            // Getters

            std::string getMediaId();
            std::string getMediaTitle();
            int getMediaYear();
            std::string getMediaGenre();


            // Setters

            void setMediaIMDBID(std::string);
            void setMediaTitle(std::string);
            void setMediaYear(int);
            void setMediaYear(std::string); // Special overloaded setter.
            void setMediaGenre(std::string);
            

        private:
            std::string _mediaID;
            std::string _mediaTitle;
            int _mediaYear;
            std::string _mediaGenre;
    };
}