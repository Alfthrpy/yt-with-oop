#ifndef _USERREACTION
#define _USERREACTION

#include <algorithm>
#include <vector>
#include "User.h"
#include "Video.h"
#include <unordered_map>
using namespace std;

class UserReaction
{
    private :
        vector <User> list_user_menyukai;
        vector <Video> list_video_disukai;
        vector <User> list_user_komen;
        vector <Video> list_video_dikomen;
        vector <string> list_komentar;
        vector <vector<string>> list_balas_komen;
        vector <vector<User>> list_user_membalas;
    public :
        void likeVideo(User user, Video &video)
        {
            list_user_menyukai.push_back(user);
            list_video_disukai.push_back(video);
            video.tambahLike();

            cout << user.getNama() << " berhasil menyukai video " << video.getJudul() << endl;
            system("pause");
        }

        void KomenVideo(User user, Video &video)
        {
            string komentar;

            cout << "Masukan Komentar : ";
            getline(cin, komentar);

            list_user_komen.push_back(user);
            list_video_dikomen.push_back(video);
            list_komentar.push_back(komentar);
            video.tambahKomen();
            cout << user.getNama() << " berhasil komen video " << video.getJudul() << endl;

            list_balas_komen.push_back(vector<string>());
            list_user_membalas.push_back(vector<User>());
            system("pause");
        }

        void displayLikeByVid(Video video)
        {
            unordered_map<string, int> userCounts; // Menggunakan unordered_map untuk mencatat jumlah suka per pengguna

            if (!list_video_disukai.empty())
            {
                cout << "Daftar user yang like video " << video.getJudul() << endl;
                for (int i = 0; i < list_video_disukai.size(); i++)
                {
                    if (list_video_disukai[i].getJudul() == video.getJudul())
                    {
                        string nama = list_user_menyukai[i].getNama();
                        userCounts[nama]++; // Menambahkan 1 ke jumlah suka pengguna menggunakan operator []
                    }
                }

                for (auto entry : userCounts)
                {
                    cout << entry.first << " : " << entry.second << " kali suka" << endl;
                }
            }
            else
            {
                cout << "Belum ada user yang like" << endl;
            }
        }

        void displaySukaVid(User *user)
        {
            if (!list_user_menyukai.empty())
            {
                cout << "\n======Daftar Video Yang Di sukai======" << endl;
                for (int i = 0; i < list_user_menyukai.size(); i++)
                {
                    if(list_user_menyukai[i].getNama() == user->getNama())
                    {
                        cout << list_video_disukai[i].getJudul() << endl;
                    }
                }
            }
            else
            {
                cout << "\nBelum ada video yang di like " << user->getNama() << endl;
            }
        }

        void displayKomenVid(User *user)
        {
            if (!list_user_komen.empty())
            {
                cout << "\n======Daftar Video Yang Dikomen======" <<  endl;
                for (int i = 0; i < list_user_komen.size(); i++)
                {
                    if (list_user_komen[i].getNama() == user->getNama())
                    {
                        cout << "video " << list_video_dikomen[i].getJudul() << endl;
                        cout << "Komentar : " << list_komentar[i] << endl;
                        cout << endl;
                    }
                }
            }
            else
            {
                cout << "\nBelum ada video yang di komen " << user->getNama() << endl;
            }
        }

        void balasKomen(User& user, Video& vid)
        {
            string nama, komen;
            cout << "Masukan nama yang ingin anda balas: ";
            getline(cin, nama);
        
            bool komentarDitemukan = false;
        
            for (int i = 0; i < list_user_komen.size(); i++)
            {
                if (list_user_komen[i].getNama() == nama && list_video_dikomen[i].getID() == vid.getID())
                {
                    cout << "Masukan Komentar: ";
                    getline(cin, komen);
                    list_balas_komen[i].push_back(komen);
                    list_user_membalas[i].push_back(user);
                    vid.tambahKomen();

                    cout << user.getNama() << " berhasil membalas komentar " << nama << " di video " << vid.getJudul() << endl;
                    komentarDitemukan = true;
                    system("pause");
                    break;
                }
            }
        
            if (!komentarDitemukan)
            {
                cout << "Komentar tidak ditemukan." << endl;
                system("pause");
            }
        }

        void displaykomen(Video vid)
        {
            cout << "***KOMENTAR :" << endl;
            if (!list_video_dikomen.empty())
            {
                for (int i = 0; i < list_video_dikomen.size(); i++)
                {
                    if (list_video_dikomen[i].getID() == vid.getID())
                    {
                        cout << list_user_komen[i].getNama() << " : " << list_komentar[i] << endl;

                        for (int j = 0; j < list_balas_komen[i].size(); j++)
                        {
                            cout << "- " << list_user_membalas[i][j].getNama() << " membalas " << list_user_komen[i].getNama() << " : " << list_balas_komen[i][j] << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Belum ada komentar" << endl;
            }
        }

        void displayWhoComment(Video video)
        {
            cout << "Daftar user yang comment video " << video.getJudul() << endl;
            unordered_map<string, int> userCounts; // Menggunakan unordered_map untuk mencatat jumlah suka per pengguna

            for (int i = 0; i < list_video_dikomen.size(); i++)
            {
                if (list_video_dikomen[i].getJudul() == video.getJudul())
                {
                    string nama = list_user_komen[i].getNama();
                    userCounts[nama]++;
                }
            }

            for(int i = 0; i < list_balas_komen.size(); i++)
            {
                for(int j = 0; j < list_balas_komen[i].size(); j++)
                {
                    string nama = list_user_membalas[i][j].getNama();
                    userCounts[nama]++;
                }
            }

            for (auto entry : userCounts)
            {
                cout << entry.first << " : " << entry.second << " kali komen" << endl;
            }
        }
};

#endif