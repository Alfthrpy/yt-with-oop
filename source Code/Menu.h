#ifndef _MENU
#define _MENU

#include <vector>
#include "Video.h"
#include "Genre.h"
#include "Channel.h"
#include "User.h"
#include "Subscription.h"
#include "UserReaction.h"
#include "Sistem.h"
#include "Playback.h"
using namespace std;

class Menu
{
    public:
        void menuUser(User *user, Sistem sistem, Playback play, UserReaction react, Subscription subs)
        {
            while(true)
            {
                system("cls");
                string pil;

                vector <Video*> videos = sistem.getVideoListUploaded();
                cout << "Login berhasil" << endl;
                cout << "Selamat datang " << user->getNama() << endl;
                cout << "====================" << endl;

                cout << "1. Tonton Video" << endl;
                cout << "2. Lihat Top Video" << endl;
                cout << "3. Search Video" << endl;
                cout << "4. Cek History" << endl;
                cout << "5. Info Pengguna" << endl;
                cout << "6. Lihat Genre Tersedia" << endl;
                cout << "7. Kembali" << endl;
                cout << "Pilihan :";
                cin >> pil;

                if(pil == "1")
                {
                    int pil_tonton;
                    if (!videos.empty())
                    {
                        system("cls");
                        cout << "Beberapa video terbaru :" << endl;
                        for(int i = 0; i < videos.size(); i++)
                        {
                            cout << i+1 << ". " << videos[i]->getJudul() << endl;
                        }
                        cout << "pilihan anda :";
                        cin >> pil_tonton;
                        play.watchVid(*(videos[pil_tonton-1]), *user, react, subs, sistem);
                    }
                    else
                    {
                        cout << "Tidak ada video tersedia" << endl;
                        system("pause");
                    }
                } 
                else if(pil == "2")
                {
                    sistem.showTopVid();
                    system("pause");
                }
                else if(pil == "3")
                {
                    Video vid = sistem.searchVideo();
                    if (!(vid.getID() == "null"))
                    {
                        string pil;
                        cout << "Apakah anda ingin menonton Video ini? (y/n): ";
                        cin >> pil;

                        if (pil == "y") 
                        {
                            play.watchVid(vid, *user, react, subs, sistem);
                        }
                    }
                    else
                    {
                        cout << "Video tidak ditemukan." << endl;
                        system("pause");
                    }
                }
                else if(pil == "4")
                {
                    play.displayHistory(*user);
                    system("pause");
                }
                else if(pil == "5")
                {
                    user->infoUser();
                    cout << "================================" << endl;
                    react.displaySukaVid(user);
                    cout << "================================" << endl;
                    react.displayKomenVid(user);
                    cout << "================================" << endl;
                    subs.getJmlSubsUser(user);
                    cout << "================================" << endl;
                    system("pause");
                }
                else if(pil == "6")
                {
                    sistem.showGenreList();
                    system("pause");
                }
                else if(pil == "7")
                {
                    menuAwal(sistem, play, subs, react);
                }
                else
                {
                    cout << "Pilihan tidak ditemukan" << endl;
                    system("pause");
                }
            }
        }

        void menuChannel(Channel *channel, Sistem sistem, Playback play, Subscription subs, UserReaction react)
        {
            system("cls");
            
            cout << "Login berhasil" << endl;
            while(true)
            {
                system("cls");
                char pil;
                cout << "\nSelamat datang " << channel->getNama() << endl;
                cout << "================" << endl;
                cout << "1. Upload Video" << endl;
                cout << "2. Tampilkan Video" << endl;
                cout << "3. Check Subscriber" << endl;
                cout << "4. Check status Video" << endl;
                cout << "5. Profil" << endl;
                cout << "6. Kembali" << endl;
                cout << "Pilihan :";
                cin >> pil;

                switch (pil)
                {
                case '1':
                    sistem.UpVideo(channel);
                    break;

                case '2':
                    cout << endl;
                    sistem.displayAllVideoChannel(channel);
                    break;

                case '3':
                    subs.getSubscriberChannel(*channel);
                    break;

                case '4':
                    sistem.checkStatsVid(react,channel);
                    break;

                case '5':
                    channel->infoChannel();
                    break;

                case '6':
                    menuAwal(sistem, play, subs, react);
                    break;
                default:
                    cout << "Input invalid" << endl;
                    system("pause");
                    break;
                }
            }
        }

        void menuAwal(Sistem& sistem,Playback play,Subscription subs, UserReaction react)
        {
            while(true){
                system("cls");
                string pil;
                vector<User*> users = sistem.getUserList();
                vector<Channel*> channels = sistem.getChannelList();

                cout << "======YOUTUBE======" << endl;
                cout << "Ingin login sebagai siapa (masukkan ID-nya)?" << endl;

                cout << "USER :" << endl;
                for (int i = 0; i < users.size(); i++) 
                {
                    cout << i + 1 << ". " << users[i]->getNama() << " ID : " << users[i]->getID() << endl;
                }

                cout << "CHANNEL :" << endl;
                for (int i = 0; i < channels.size(); i++) 
                {
                    cout << i + 1 << ". " << channels[i]->getNama() << " ID : " << channels[i]->getID() << endl;
                }

                cout << "Pilihan :" << endl;
                cin >> pil;

                for (auto user : users)
                {
                    if (user->getID() == pil) 
                    {
                        menuUser(user, sistem,play,react,subs);
                        return;
                    }
                }

                for (auto channel : channels)
                {
                    if (channel->getID() == pil) 
                    {
                        menuChannel(channel,sistem,play,subs,react);
                        return;
                    }
                }
                cout << "ID tidak valid!" << endl;
                system("pause");
            }
        }
};

#endif