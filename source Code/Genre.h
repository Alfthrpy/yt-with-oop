#ifndef _GENRE
#define _GENRE

#include <iostream>
#include <string>
#include <vector>
#include "Video.h"
using namespace std;

class Genre
{
    private :
        string nama;
        vector <Video*> list_video;
    public :
        Genre(string nama)
        {
            this->nama = nama;
        }
        
        void addVidToGenre(Video *vid)
        {
            list_video.push_back(vid);
        }

        void showListVideo()
        {
            if (list_video.empty())
            {
                cout << "Tidak ada video pada genre ini" << endl;
            }
            else
            {
                cout << "Daftar Video pada Genre " << nama << " :" << endl;
                for (int i = 0; i < list_video.size(); i++)
                {
                    cout << i+1 << ". " << (*list_video[i]).getJudul();
                    cout << endl;
                }
            }
        }

        string getNama()
        {
            return nama;
        }
};

#endif