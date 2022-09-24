/***************************

For Binary search I used our lecture slides and the following video:
https://youtu.be/B25Gu5r0xUg

I decided to use bubble sort and used lecture slides and the youtube video explaining it on canvas:
https://youtu.be/xli_FI7CuzA

 ***************************/
/*
Name: Ben Skinner                      NetID: bts277
Date: 4/16/2022                    Due Date: 4/18/2022
Description: A program that manages a playlist by sorting, shuffling, and searching it.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "song.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

// given to you
void processFile(vector<Song> &playlist);

// you should create
void shuffle(vector<Song> &playlist);
int binarySearch(vector<Song> &playlist, string songName);
void displayPlaylist(vector<Song> &playlist);
void Sort(vector<Song> &playlist);
// add your own sort function

int main()
{
    vector<Song> playlist;

    // sets up playlist
    processFile(playlist);

    cout << "\nInitial playlist: " << endl;
     displayPlaylist(playlist);

    cout << "\nWelcome to the playlist display manager." << endl << endl;



    while(true)
{
   string option;

   cout << "0. Exit" << endl;
   cout << "1. Sort Playlist" << endl;
   cout << "2. Shuffle Playlist" << endl;
   cout << "3. Search Playlist" << endl;
   cout << "Which option would you like? ";
   cin >> option;

   if(option == "0")
{
     break;
}
   else if(option == "1")
{
     Sort(playlist);
     cout << endl;
     displayPlaylist(playlist);
     cout << endl;

}

   else if(option == "2")
{
    shuffle(playlist);
    cout << endl;
    displayPlaylist(playlist);
    cout << endl;
}
   else if(option == "3")
{
     string title;
     cout << "what is the name of the song? ";

     cin.ignore();

     getline(cin, title);

     int searchedSong = binarySearch(playlist, title);

     if(searchedSong != -1)
{
        cout << '\n' <<playlist[searchedSong].getTitle() << " - " << playlist[searchedSong].getArtist() << endl << endl;
}
          else
{
        cout << "\nCouldn't find the song, sorry! :'(" << endl << endl;
}

}

   else
   {
       cout << endl << "That's not a valid menu option. Try again." << endl;
   }
}
    return 0;
}

void processFile(vector<Song> &playlist)
{
    ifstream infile;
    string line;

    infile.open("songs.txt");

    if(infile.is_open())
{
        cout << "Successful songs opening." << endl;
}

    else
{
        cout << "Couldn't locate file. Program closing." << endl;
        exit(EXIT_FAILURE);
}

    while(getline(infile, line))
{
        // first line --> song
        // second line --> artist

        if(line != "")
{
            string song, artist;

            song = line;

            getline(infile, artist);

            Song temp(song, artist);

            playlist.push_back(temp);
}
}


    return;
}



int binarySearch(vector<Song> &playlist, string songName)
{

    Sort(playlist);

    int size;
    size = playlist.size();
    int left = 0, right = size - 1, mid;

    while(right >= left)
{
        mid = (right + left) / 2;
        if(playlist[mid].getTitle() < songName)
{
            left = mid + 1;
}

        else if(playlist[mid].getTitle() > songName)
{
            right = mid - 1;
}

        else
{
            return mid;
}
}


    return -1;
}
void displayPlaylist(vector<Song> &playlist)
{

    for (unsigned int i = 0; i < playlist.size(); i++)
{

        cout << playlist[i].getTitle() << " - " << playlist[i].getArtist() << endl;

}

}
void Sort(vector<Song> &playlist)
{

    int size = playlist.size();
    for(int i= 0; i < size - 1; i++)
{
    int smallVal = i;
    for(int x = i + 1; x < size; x++)
{
    if(playlist[x].getTitle() < playlist[smallVal].getTitle())
{
    smallVal = x;
}
}
    string song, artist;

     Song temp(song, artist);
     temp = playlist[i];

     playlist[i] = playlist[smallVal];
     playlist[smallVal] = temp;
}

}
 void shuffle(vector<Song> &playlist)
{
     srand(time(NULL));

        for (int i = 0; i < playlist.size(); i++)
{
            int swapped = rand() % playlist.size();
            auto temp = playlist[i];

            playlist[i] = playlist[swapped];
            playlist[swapped] = temp;
}

}





