#pragma once
#include <set>
#include <string>
#include <vector>
#include <stdexcept>
#include "Song.h"

class SongCollection {
public:
    SongCollection(const std::string& filepath);
    void addSong(const Song& song);
    void removeSong(const std::string& title);
    void display(std::ostream& out) const;

    std::set<std::string> uniqueArtists;

protected:
    std::vector<Song> songs_;
    
    void loadFromFile(const std::string& filepath);
};

