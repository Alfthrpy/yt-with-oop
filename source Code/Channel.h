#ifndef _CHANNEL
#define _CHANNEL
#include <vector>
#include <iostream>
#include "Video.h"
#include "User.h"
using namespace std;

class Channel
{
	private:
		vector<Video*> listVideo;
		User *owner;
		string namaChannel;
		string tglGabung;
		string ID;
		int jmlSubscriber;
		
	public:
		Channel(string nama_channel, User *owner, string tgl_gabung, string ID)
		{
			namaChannel = nama_channel;
			this->owner = owner;
			this->ID = ID;
			tglGabung = tgl_gabung;
			jmlSubscriber = 0;
		}
		
		// int getJumlahVideo()
		// {
		// 	return listVideo.size();		
		// }
		
		void tambahSubsriber()
		{
			jmlSubscriber++;
		}

        void kurangSubscriber()
		{
            jmlSubscriber--;
        }
		
		void uploadVideo(Video *upload)
		{
			listVideo.push_back(upload);
			cout << endl;
			cout << "===Video Berhasil di upload===" << endl;
			upload->infoVideo();
		}

		void displayVid()
		{
			for(auto i : listVideo)
			{
				i->infoVideo();
			}
		}

		string getNama()
		{
			return namaChannel;
		}

		string getID()
		{
			return ID;
		}

		vector<Video*> getListVideo()
		{
			return listVideo;
		}
		
		void infoChannel()
		{
			cout<<"\nNama channel     : "<<namaChannel<<endl;
			cout<<"Nama Owner       : "<<owner->getNama()<<endl;
			cout<<"Tanggal gabung   : "<<tglGabung<<endl;
			cout<<"Jumlah subscriber: "<<jmlSubscriber<<endl;
			cout<<"Jumlah video     : "<<listVideo.size()<<endl;
			system("pause");
		}
};

#endif