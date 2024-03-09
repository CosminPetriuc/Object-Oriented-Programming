#include "Song.h"
#include <algorithm>
#include <cctype>
#include <sstream>

// Constructor
Song::Song(const std::string& artist, const std::string& title, const std::string& lyrics) : artist_(artist), title_(title) {
    splitLyrics(lyrics);
}

// Public member functions
std::string Song::getArtist() const {
    return artist_;
}

std::string Song::getTitle() const {
    return title_;
};


std::vector<std::string> Song::getLyrics() const {
    return lyrics_;
}

// Private member functions
void Song::splitLyrics(const std::string& lyrics) {
    std::istringstream iss(lyrics);
    std::string word;

    while (iss >> word) {
        // Remove any non-alphabetic characters from the word
        word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return !std::isalpha(c); }), word.end());

        // Convert the word to lowercase
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });

        // Add the word to the lyrics vector
        if (!word.empty()) {
            lyrics_.push_back(word);
        }
    }
}
