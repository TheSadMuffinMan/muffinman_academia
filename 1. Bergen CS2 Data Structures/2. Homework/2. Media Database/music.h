#pragma once

#include <media.h>
#include <iostream>

namespace musicNamespace
{
    class MusicClass: public media::MediaClass
    {
        public:
            MusicClass();
            ~MusicClass();

            void displayInfo();

            // Native Getters
            std::string getComposer();
            std::size_t getNumTracks();
            float getTotalPlaytime();

            // Native Setters
            void setComposer(std::string);
            void setNumTracks(int);
            void setNumTracks(std::string);
            void setTotalPlaytime(float);
            void setTotalPlaytime(std::string);

        private:
            std::string _composer;
            int _numTracks;
            float _totalPlaytime; // In seconds (pedantic)
    };
}