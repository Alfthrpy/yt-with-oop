#ifndef _USER
#define _USER

#include <iostream>
#include <string>
using namespace std;

class User
{
    private:
        string nama;
        string gmail;
        int umur;
        string username;
        string ID;
    public:
        User(string nama, string gmail, int umur, string username,string ID)
        {
            this->nama = nama;
            this->gmail = gmail;
            this->umur = umur;
            this->username = username;
            this->ID = ID;
        } 

        void infoUser()
        {
            cout << "ID Pengguna :" << ID << endl;
            cout << "Nama        :" << nama << endl;
            cout << "Username    :" << username << endl;
            cout << "Gmail       :" << gmail << endl;
            cout << "Umur        :" << umur << endl;
        }

        string getID()
        {
            return ID;
        }

        string getNama()
        {
            return nama;
        }
};

#endif