#pragma once

#include <media.h>
#include <movie.h>
#include <tvshows.h>
#include <music.h>

#include <string>
#include <iomanip>

class Database
{
    public:
        Database(); // Complete.
        ~Database(); // Working on.

        void loadData();
        // Load data

        // Add Movie
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

    private:
        std::string _name;
        int _db_id;
        std::size_t numMovies;
        std::size_t numTVShows;
        std::size_t numMusicObjects;

        movieNamespace::MovieClass* movieList[100];
        tvShowNamespace::TVShowClass* tvShowList[100];
        musicNamespace::MusicClass* musicList[100];
};