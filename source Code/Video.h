#ifndef _VIDEO
#define _VIDEO
#include <iostream>
#include <string>
using namespace std;

class Video
{
	private:
		string judul;
		string tgl_upload;
		string deskripsi;
		string durasi;
		string isi_video;
		string ID;
		int jml_like = 0;
		int jml_komen = 0;
		int jml_viewers = 0;
	public:
		Video(string ID)
		{
			this->ID = ID;
		}
		
		int getJumlahLike()
		{
			return jml_like;
		}
		
		int getJumlahKomen()
		{
			return jml_komen;
		}

		int getJumlahViewers()
		{
			return jml_viewers;
		}
		
		void tambahLike()
		{
			jml_like++;
		}
		
		void tambahKomen()
		{
			jml_komen++;
		}

		void tambahViewers()
		{
			jml_viewers++;
		}

		string getID()
		{
			return ID;
		}

		string getJudul()
		{
			return judul;
		}

		void setJudul(string Judul)
		{
			judul = Judul;
		}

		void setTgl_upload(string Tgl_upload)
		{
			tgl_upload = Tgl_upload;
		}

		void setDeskripsi(string Deskripsi)
		{
			deskripsi = Deskripsi;
		}

		void setDurasi(string Durasi)
		{
			durasi = Durasi;
		}

		void setIsi_video(string Isi_video)
		{
			isi_video = Isi_video;
		}

		// void setJml_like(int Jml_like)
		// {
		// 	jml_like = Jml_like;
		// }

		// void setJml_komen(int Jml_komen)
		// {
		// 	jml_komen = Jml_komen;
		// }

		// void setJml_viewers(int Jml_viewers)
		// {
		// 	jml_viewers = Jml_viewers;
		// }
		
		// void downloadVideo(User download){
		// 	cout<<"Video "<<judul<<" berhasil diunduh"<<endl;
		// }
		
		void infoVideo()
		{
			cout<<"ID		 : "<<ID<<endl;
			cout<<"Judul video      : "<<judul<<endl;
			cout<<"Tanggal upload   : "<<tgl_upload<<endl;
			cout<<"Deskripsi video  : "<<deskripsi<<endl;
			cout<<"Durasi video     : "<<durasi<<endl;
			cout<<"Isi video        : "<<isi_video<<endl;
			cout<<"Jumlah penonton  : "<<jml_viewers<<endl;
			cout<<"Jumlah disukai   : "<<jml_like<<endl;
			cout<<"Jumlah komentar  : "<<jml_komen<<endl;
		}
};

#endif