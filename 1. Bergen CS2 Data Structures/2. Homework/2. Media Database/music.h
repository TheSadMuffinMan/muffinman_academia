#pragma once

#include <media.h>
#include <iostream>
#include <sstream>

namespace musicNamespace
{
    class MusicClass: public media::MediaClass
    {
        public:
            MusicClass();
            ~MusicClass();

            // Virtual inherited function.
            void displayInfo();


            // Native Getters

            std::string getComposer();
            std::size_t getNumTracks();
            float getTotalPlaytime();


            // Native Setters

            void setComposer(std::string);
            void setNumTracks(int);
            void setNumTracks(std::string); // Special overloaded function.
            void setTotalPlaytime(float);
            void setTotalPlaytime(std::string); // Special overloaded function.

        private:
            std::string _composer;
            int _numTracks;
            float _totalPlaytime; // In seconds.
    };
}