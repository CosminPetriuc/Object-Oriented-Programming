#include <iostream>
#include "SongCollection.h"
#include "Song.h"

int main() {
    try {
        SongCollection song_collection("path/to/songs.csv");
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    SongCollection collection("songs.txt");

    collection.addSong(Song("Kendrick Lamar", "DNA", "I got, I got, I got, I got..."));
    collection.addSong(Song("Kendrick Lamar", "HUMBLE", "Wicked or weakness? You gotta see this..."));
    collection.addSong(Song("J. Cole", "Middle Child", "I'm the middle child, that mean I'm the older brother..."));
    collection.addSong(Song("J. Cole", "No Role Modelz", "First things first: rest in peace, Uncle Phil..."));
    collection.addSong(Song("Kanye West", "Ultralight Beam", "We don't want no devils in the house, God"));
    collection.addSong(Song("Kanye West", "Runaway", "And I always find, yeah, I always find somethin' wrong..."));
    collection.addSong(Song("Drake", "God's Plan", "And they wishin' and wishin' and wishin' and wishin'..."));
    collection.addSong(Song("Drake", "In My Feelings", "Kiki, do you love me? Are you riding?"));
    collection.addSong(Song("Travis Scott", "SICKO MODE", "Astro, yeah / Sun is down, freezin' cold..."));
    collection.addSong(Song("Travis Scott", "Goosebumps", "I get those goosebumps every time, yeah..."));

    collection.addSong(Song("BTS", "Dynamite", "Cos ah ah I’m in the stars tonight..."));
    collection.addSong(Song("BTS", "Butter", "Smooth like butter, like a criminal undercover..."));
    collection.addSong(Song("BLACKPINK", "DDU-DU DDU-DU", "BLACKPINK in your area..."));
    collection.addSong(Song("BLACKPINK", "Kill This Love", "Yeah, yeah, yeah..."));
    collection.addSong(Song("TWICE", "Fancy", "You know I want it, I’m not shy"));
    collection.addSong(Song("TWICE", "Feel Special", "You make everything alright..."));
    collection.addSong(Song("Red Velvet", "Psycho", "Ooh, ah, ah, look at my, look at my..."));
    collection.addSong(Song("Red Velvet", "Bad Boy", "Who dat who dat who dat boy"));
    collection.addSong(Song("EXO", "Love Shot", "Jeonghaejin geon jeonyeok itji..."));
    collection.addSong(Song("EXO", "Growl", "Nae seutaillo nae nae nae nae nae..."));

    
    return 0;
}