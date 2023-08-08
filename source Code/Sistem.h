#ifndef _SISTEM
#define _SISTEM
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <Windows.h>
#include "Video.h"
#include "Genre.h"
#include "Channel.h"
#include "User.h"
#include "UserReaction.h"
using namespace std;

class Sistem
{
    private:
        vector<Video*> list_all_vid_uploaded;
        vector<Video*> list_all_vid_unuploaded;
        vector<Channel*> list_all_channel;
        vector<Genre*> list_all_genres;
        vector<User*> list_all_users;
        unordered_map<string,int> dict_vid_dengan_nilai;

    public:
        void addVidToListUploaded(Video *vid)
        {
            list_all_vid_uploaded.push_back(vid);
        }

        void addVidToListUnuploaded(Video *vid)
        {
            list_all_vid_unuploaded.push_back(vid);
        }

        void addChannelsToList(Channel *chn)
        {
            list_all_channel.push_back(chn);
        }

        void addGenresToList(Genre *genre)
        {
            list_all_genres.push_back(genre);
        }

        void addUsersToList(User *users)
        {
            list_all_users.push_back(users);
        }

        vector<Video*> getVideoListUploaded()
        {
            return list_all_vid_uploaded;
        }

        // vector<Video*> getVideoListUnuploaded()
        // {
        //     return list_all_vid_unuploaded;
        // }

        vector<Channel*> getChannelList()
        {
            return list_all_channel;
        }

        vector<User*> getUserList()
        {
            return list_all_users;
        }

        Video* SearchVid(string ops)
        {
            cout << "Mencari video diperangkat..." << endl;
            Sleep(3);
            for(int i = 0; i < list_all_vid_unuploaded.size(); i++)
            {
                if(list_all_vid_unuploaded[i]->getID() == ops)
                {
                    cout << "Video Ditemukan!" << endl;
                    Video *vid = list_all_vid_unuploaded[i];
                    list_all_vid_unuploaded.erase(remove(list_all_vid_unuploaded.begin(),list_all_vid_unuploaded.end(), list_all_vid_unuploaded[i]),list_all_vid_unuploaded.end());
                    return vid;
                }
            }
            cout << "Video Tidak Ditemukan!" << endl;
            system("pause");
            return 0;
        }

        Genre* SeachGenre(string ops)
        {
            for(int i = 0; i < list_all_genres.size(); i++)
            {
                if((*list_all_genres[i]).getNama() == ops)
                {
                    cout << "Genre Ditemukan!" << endl;
                    Genre *genre = list_all_genres[i];
                    return genre;
                }
            }
            cout << "Genre Tidak Ditemukan!" << endl;
            system("pause");
            return 0;
        }

        void UpVideo(Channel *channel)
        {
            system("cls");
            string ops;
            cout << "=======Youtube Studio======" << endl;
            displayAllVideoUnup();
            cout << "Masukan ID Video : ";
            cin >> ops;

            if (Video *video = SearchVid(ops))
            {
                cout << "Masukan Judul Video : ";
                cin.ignore();
                getline(cin, ops);
                video->setJudul(ops);
                cout << "Masukan Deksripsi Video : ";
                getline(cin, ops);
                video->setDeskripsi(ops);
                cout << "Masukan Isi Video : ";
                cin >> ops;
                cin.ignore();
                video->setIsi_video(ops);
                cout << "Masukan Durasi Video : ";
                cin >> ops;
                cin.ignore();
                video->setDurasi(ops);
                cout << "Masukan Tanggal Upload Video : ";
                cin >> ops;
                cin.ignore();
                video->setTgl_upload(ops);

                addVidToListUploaded(video);
                channel->uploadVideo(video);
                cout << "Video Berhasil Ditambahkan" << endl;

                cout << "Apa Genre Video ini(Musik, Game, Pendidikan)? ";
                cin >> ops;
                cin.ignore();
                if (Genre *genre = SeachGenre(ops))
                {
                    genre->addVidToGenre(video);
                    cout << "Berhasil Ditambah ke Genre " << genre->getNama() << endl;
                    system("pause");
                }
            }
        }

        // void addUser()
        // {
            
        // }

        void displayAllVideoChannel(Channel *channel)
        {
            cout << "Video yang di telah di upload :" << endl;
            for(auto i : channel->getListVideo())
            {
                cout << "=========" << endl;
                i->infoVideo();
                cout << endl;
            }
            system("pause");
        }

        void displayAllVideoUnup()
        {
            cout << "Daftar ID Video yang Tersedia : " << endl;
            for(auto i : list_all_vid_unuploaded)
            {
                cout << (*i).getID() << endl;
            }
        }

        Channel searchChannelWithVid(Video* video)
        {
            for(auto i : list_all_channel)
            {
                vector<Video*> vids_channel = i->getListVideo();
                for(auto j : vids_channel)
                {
                    if(j->getID() == video->getID())
                    {
                        return *i;
                    }
                }
            }
            cout << "Tidak Ditemukan" << endl;
        }

        Video searchVideo()
        {
            string judul;
            Video vid_null("null");
            cout << "Masukan Judul Video : ";
            getline(cin, judul);
            cin.ignore();

            for(auto i : list_all_vid_uploaded)
            {
                if(i->getJudul() == judul)
                {
                    cout << "Mencari Video..." << endl;
                    Sleep(2);
                    cout << "Video Ditemukan!" << endl;
                    i->infoVideo();
                    return *i;
                }
            }
            return vid_null;
        }

        void checkStatsVid(UserReaction react, Channel *channel)
        {
            vector<Video*> vid_channel = channel->getListVideo();
            if (!vid_channel.empty())
            {
                cout << "Video mana yang ingin di check (masukan ID) : " << endl;
                for(auto i : vid_channel)
                {
                    cout << i->getJudul() << " ID : " << i->getID() << endl;
                }
                
                string pil;
                cout << "Pilihan : ";
                cin >> pil;

                for(auto i : vid_channel)
                {
                    if(i->getID() == pil)
                    {
                        system("cls");
                        cout << "Video " << i->getJudul() << " :" << endl;
                        cout << "=====JUMLAH INTERAKSI=====" << endl;
                        cout << "Jumlah like :" << i->getJumlahLike() << endl;
                        cout << "Jumlah Viewers :" << i->getJumlahViewers() << endl;
                        cout << "Jumlah komen :" << i->getJumlahKomen() << endl;
                        cout << endl;
                        cout << "======USER YANG BERINTERAKSI=======" << endl;
                        react.displayLikeByVid(*i);
                        cout << endl;
                        react.displayWhoComment(*i);
                        cout << endl;
                        system("pause");
                    }
                }
            }
        }

        void showTopVid()
        {
            vector <pair<string, int>> topVid;
            int kalkulasi_vid;
            for(auto vid : list_all_vid_uploaded)
            {
                kalkulasi_vid = (*vid).getJumlahLike() + (*vid).getJumlahViewers();
                topVid.push_back(make_pair((*vid).getID(), kalkulasi_vid));
            }

            sort(topVid.begin(), topVid.end(), [](pair<string, int> a, pair<string, int> b)
            {
                return a.second > b.second;
            });

            cout << "==Top Video==" << endl;
            if (!topVid.empty())
            {
                for (int i = 0; i < topVid.size(); i++)
                {
                    string vid_id = topVid[i].first;
                    for (int j = 0; j < list_all_vid_uploaded.size(); j++)
                    {
                        if ((*list_all_vid_uploaded[j]).getID() == vid_id)
                        {
                            cout << i+1 << ". " << (*list_all_vid_uploaded[i]).getJudul() << endl;
                            cout << "- Dengan kalkulasi : " << topVid[i].second << endl;
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << "Tidak ada video yang terdaftar" << endl;
            }
        }

        void showGenreList()
        {
            int pil_genre;
            cout << "Daftar genre yang tersedia : \n";
            for(int i = 0; i < list_all_genres.size(); i++)
            {
                cout << i+1 << ". " << (*list_all_genres[i]).getNama() << endl;
            }
            cout << endl;
            cout << "Pilih Genre : ";
            cin >> pil_genre;
            (*list_all_genres[pil_genre - 1]).showListVideo();
        }
};

#endif