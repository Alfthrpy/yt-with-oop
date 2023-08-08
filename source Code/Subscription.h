#ifndef _SUBSCRIPTION
#define _SUBSCRIPTION

#include <vector>
#include "Channel.h"
#include "User.h"
#include "Sistem.h"
#include <iostream>

using namespace std;

class Subscription
{
    private :
        vector <Channel> list_channel;
        vector <User> list_user;
    public :
        void Subscribe(User user, Video vid, Sistem sistem)
        {
            Channel channel = sistem.searchChannelWithVid(&vid);

            if (checkSubs(user,channel))
            {
                cout << "Anda telah subscribe channel ini" << endl;
            } 
            else
            {
                list_user.push_back(user);
                list_channel.push_back(channel);
                channel.tambahSubsriber();
                cout << user.getNama() << " berhasil subscribe " << channel.getNama() << endl;
                system("pause");
            } 
        }

        void Unsubscribe(User user, Video vid, Sistem sistem)
        {
            Channel channel = sistem.searchChannelWithVid(&vid);

            channel.kurangSubscriber();
            for (int i = 0; i < list_user.size() && i < list_channel.size(); i++)
            {
                if (list_user[i].getNama() == user.getNama() && list_channel[i].getNama() == channel.getNama())
                {
                    list_user.erase(list_user.begin() + i);
                    list_channel.erase(list_channel.begin() + i);
                }
            }
            cout << user.getNama() << " berhasil unsubscribe " << channel.getNama() << endl;
            system("pause");
        }


        void getSubscriberChannel(Channel channel)
        {
            cout << "\nDaftar yang Subsribe " << channel.getNama() << " yaitu :" << endl;
            int jmlSubs = 0;
            for (int i = 0; i < list_channel.size(); i++)
            {
                if (list_channel[i].getNama() == channel.getNama())
                {
                    cout << i+1 << ". " << list_user[i].getNama() << endl;
                    jmlSubs++;
                }
            }
            cout << "Jumlah pengguna yang mensubcribe channel " << channel.getNama() << " : " << jmlSubs << endl;
            system("pause");
        }

        void getJmlSubsUser(User *user)
        {
            if(!list_user.empty()){
                cout << "\n======Daftar Channel yang di Subsribe======" << endl;
                int jmlSubsUs = 0;
                for (int i = 0; i < list_user.size(); i++)
                {
                    if (list_user[i].getNama() == user->getNama())
                    {
                        cout << i+1 << ". " << list_channel[i].getNama() << endl;
                        jmlSubsUs++;
                    }
                }
                cout << "Jumlah channel yang disubsribe oleh " << user->getNama() << " : " << jmlSubsUs << endl;
            } else {
                cout << "\nBelum ada channel yang di subsribe" << endl;
            }
        }

        // void display_subs(Channel channel)
        // {
        //     for(int i = 0; i < list_channel.size(); i++)
        //     {
        //         if(list_channel[i].getID() == channel.getID())
        //         {
        //             cout << i+1 << ". " << list_user[i].getNama() << endl;
        //         }
        //     }
        // }

        bool checkSubs(User user, Channel channel)
        {
            for(int i = 0; i < list_channel.size(); i++)
            {
                if(list_user[i].getID() == user.getID() && list_channel[i].getID() == channel.getID())
                {
                    return true;
                }
            }
            return false;
        }
};

#endif