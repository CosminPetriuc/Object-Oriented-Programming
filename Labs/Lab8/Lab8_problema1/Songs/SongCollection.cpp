#include "SongCollection.h"
#include <fstream>

SongCollection::SongCollection(const std::string& filepath) {
    loadFromFile(filepath);
}

void SongCollection::addSong(const Song& song) {
    songs_.push_back(song);
}

void SongCollection::removeSong(const std::string& title) {
    auto song_it = std::find_if(songs_.begin(), songs_.end(),
        [title](const Song& song) { return song.getTitle() == title; });
    if (song_it == songs_.end()) {
        throw std::invalid_argument("Song not found");
    }
    songs_.erase(song_it);
}

void SongCollection::display(std::ostream& out) const {
    for (const auto& song : songs_) {
        out << "Artist: " << song.getArtist() << std::endl;
        out << "Title: " << song.getTitle() << std::endl;
        out << "Lyrics:" << std::endl;
        const auto& lyrics = song.getLyrics();
        for (const auto& line : lyrics) {
            out << line << std::endl;
        }
        out << std::endl;
    }
}


void SongCollection::loadFromFile(const std::string& filepath) {
    std::ifstream infile(filepath);
    if (!infile.is_open()) {
        throw std::invalid_argument("Error: Could not open file " + filepath);
    }

    std::string line;
    while (std::getline(infile, line)) {
        size_t delim_pos = line.find_first_of(',');
        if (delim_pos == std::string::npos) {
            continue; // Skip line if there is no delimiter
        }

        std::string artist = line.substr(0, delim_pos);
        std::string title = line.substr(delim_pos + 1);

        // Read lyrics from subsequent lines until the next comma-separated line is encountered
        std::string lyrics;
        while (std::getline(infile, line)) {
            if (line.empty() || line.find_first_of(',') != std::string::npos) {
                break; // End of lyrics or new song
            }
            lyrics += line + '\n';
        }

        Song song(artist, title, lyrics);
        songs_.push_back(song);
    }

    infile.close();
}

