#pragma once

#include <string>
#include <iomanip>
#include <fstream>

#include "media.h"
#include "movie.h"
#include "tvshows.h"
#include "music.h"

class Database
{
    public:

        // Default constructors and destructors

        Database(); // Complete.
        ~Database(); // Incomplete.


        void loadData(); // Working on.

        void addMovie(movieNamespace::MovieClass*); // Working!!!!!!!!!!! FINALLLLLLYYYYYYYYYYYYYYYYY
        void incrementNumMovies(); // Working.

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

        movieNamespace::MovieClass* getMovieArrayAddress();
        // tvShowNamespace::TVShowClass* getTVShowArrayAddress();
        // musicNamespace::MusicClass* getMusicArrayAddress();

        // Setters

        void setNumMovies(std::size_t);
        // void setNumTVShows(std::size_t);
        // void setNumMusicObjects(std::size_t);

        void setMovieArray(movieNamespace::MovieClass*, std::size_t);

    private:
        std::string _name; // More or less garbage variable.
        int _db_id; // See above.

        std::size_t _numMovies;
        std::size_t _numTVShows;
        std::size_t _numMusicObjects;

        movieNamespace::MovieClass* _movieArray[100];
        tvShowNamespace::TVShowClass* _tvShowArray[100];
        musicNamespace::MusicClass* _musicArray[100];
};