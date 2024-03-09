#pragma once

#include <string>
#include <vector>

class Song {
public:
    Song(const std::string& artist, const std::string& title, const std::string& lyrics);

    std::string getArtist() const;
    std::string getTitle() const;
    std::vector<std::string> getLyrics() const;

protected:
    std::string artist_;
    std::string title_;
    std::vector<std::string> lyrics_;  

    void splitLyrics(const std::string& lyrics);
};