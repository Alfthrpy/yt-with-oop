#ifndef _PLAYBACK
#define _PLAYBACK

#include <iostream>
#include <vector>       
#include <string>       
#include <unordered_map>       
#include <algorithm>           
#include <set>                 
#include "User.h"
#include "Video.h"
#include "UserReaction.h"
#include "Subscription.h"
#include "Sistem.h"
using namespace std;

class Playback
{
    private:
        vector<User>list_user_yang_menonton;
        vector<Video>list_video_yang_ditonton;
    public:
        void watchVid(Video& vid, User user, UserReaction& react, Subscription& subs, Sistem sistem)
        {
            list_user_yang_menonton.push_back(user);
            list_video_yang_ditonton.push_back(vid);
            vid.tambahViewers();

            while(true){
                system("cls");
                cout << "====VIDEO SEDANG DIPUTAR OLEH "<< user.getNama() << "====" << endl;
                vid.infoVideo();
                Suggestion(vid);
                react.displaykomen(vid);

            
                
                string pil;
                cout << endl;
                cout << "Anda ingin melakukan apa : " << endl;
                cout << "1. like" << endl;
                cout << "2. komen" << endl;
                cout << "3. balas komen" << endl;
                cout << "4. Subscribe channel" << endl;
                cout << "5. Unsubsribe channel" << endl;
                cout << "6. Kembali" << endl;
                cout << "Pilihan : ";
                cin >> pil;
                cin.ignore();

                if (pil == "1")
                {
                    react.likeVideo(user,vid);
                } 
                else if(pil == "2")
                {
                    react.KomenVideo(user,vid);
                } 
                else if(pil == "3")
                {
                    react.balasKomen(user,vid);
                }
                else if(pil == "4")
                {
                    subs.Subscribe(user, vid, sistem);
                } 
                else if(pil == "5")
                {
                    subs.Unsubscribe(user, vid, sistem);
                }
                else if(pil == "6")
                {
                    break;
                }
                else
                {
                    cout << "Pilihan tidak tersedia" << endl;
                    system("pause");
                    break;
                }
            }
        }

        vector<Video> getHistory(User user)
        {
            vector<Video> list_temp_video;
            for(int i = 0; i < list_user_yang_menonton.size(); i++)
            {
                if (list_user_yang_menonton[i].getID() == user.getID())

                {
                    list_temp_video.push_back(list_video_yang_ditonton[i]);
                }
            }
            return list_temp_video;  
        }

        void displayHistory(User user)
        {
            if (!getHistory(user).empty())
            {
                cout << "====HISTORY VIDEO PENGGUNA====" << endl;
                int jmlVid = 0;
                for(auto i : getHistory(user))
                {
                    cout << i.getJudul() << endl;
                    jmlVid++;
                }
                cout << "Jumlah video yang ditonton " << user.getNama() << " yaitu : " << jmlVid << endl;
            }
            else
            {
                cout << "Belum ada video yang ditonton " << user.getNama() << endl;
            }
        }

        // vector<User> getViewers(Video vid)
        // {
        //     vector<User>list_temp_user;
        //     for(int i = 0; i < list_video_yang_ditonton.size(); i++)
        //     {
        //         if (list_video_yang_ditonton[i].getID() == vid.getID())
        //         {
        //             list_temp_user.push_back(list_user_yang_menonton[i]);
        //         }
        //     }
        //     return list_temp_user;
        // }

        // void displayViewers(Video vid)
        // {
        //     cout << "Viewers video : " << vid.getJudul() << endl;
        //     for(auto i : getViewers(vid))
        //     {
        //         cout << i.getNama() << endl;
        //     }
        // }

        vector<string> hitungVidSuggest(vector<string> list_vid)
        {
            unordered_map<string,int> dict_nilai;
            for(const string& nilai : list_vid)
            {
                dict_nilai[nilai]++;
            }

            sort(list_vid.begin(), list_vid.end(), [&](const string& a, const string& b)
            {
                return dict_nilai[a] > dict_nilai[b];
            });

            set<string> unik(list_vid.begin(), list_vid.end());
            list_vid.assign(unik.begin(), unik.end());

            return list_vid;

        }

        void Suggestion(Video vid)
        {
            vector<string> list_vid;

            for(int i = 0; i < list_video_yang_ditonton.size(); i++)
            {
                if(list_video_yang_ditonton[i].getID() == vid.getID())
                {
                    User temp_user = list_user_yang_menonton[i];
                    int batas_cari = 0;
                    for(int j = i+1; j < list_user_yang_menonton.size(); j++)
                    {
                        if (batas_cari == 2)
                        {
                            break;
                        }
                        
                        if(list_user_yang_menonton[j].getID() == temp_user.getID())
                        {
                            list_vid.push_back(list_video_yang_ditonton[j].getJudul());
                            batas_cari += 1;
                        }
                    }
                }
            }

            cout << endl;
            cout << "***Suggestion : " << endl;
            for(auto i : hitungVidSuggest(list_vid))
            {
                cout << i << endl;
            }
            cout << endl;
        }
};

#endif