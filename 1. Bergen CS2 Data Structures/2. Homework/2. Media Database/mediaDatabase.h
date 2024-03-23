#pragma once

#include <media.h>
#include <movie.h>
#include <tvshows.h>
#include <music.h>

#include <string>
#include <iomanip>
#include <fstream>

class Database
{
    public:

        // Default constructors and destructors

        Database(); // Complete.
        ~Database(); // Incomplete.


        void loadData(); // Incomplete, working on.

        // Add Movie // Incomplete, working on.
        movieNamespace::MovieClass* addMovie(std::size_t, movieNamespace::MovieClass*, movieNamespace::MovieClass*);
        // Add TV Show
        // Add Music

        // Display all media.
        // Display single movie.
        // Display single TV show.
        // Display single Music.

        // Remove single movie.
        // Remove single TV show.
        // Remove single Music.

        // Output all data to CSV.

        // Search for media.

        // Getters

        std::size_t getNumMovies();
        std::size_t getNumTVShows();
        std::size_t getNumMusicObjects();


        // Setters

    private:
        std::string _name;
        int _db_id;
        std::size_t _numMovies;
        std::size_t _numTVShows;
        std::size_t _numMusicObjects;

        movieNamespace::MovieClass* _movieList[100];
        tvShowNamespace::TVShowClass* _tvShowList[100];
        musicNamespace::MusicClass* _musicList[100];
};