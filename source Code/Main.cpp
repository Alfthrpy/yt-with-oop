#include <iostream>
#include "Video.h"
#include "Genre.h"
#include "Channel.h"
#include "User.h"
#include "Subscription.h"
#include "UserReaction.h"
#include "Sistem.h"
#include "Playback.h"
#include "Menu.h"
using namespace std;

int main()
{
    Sistem sistem;

    Genre genre1("Musik");
    Genre genre2("Game");
    Genre genre3("Pendidikan");

    UserReaction react;

    Subscription subs;

    Playback play;

    Menu menu;

    system("cls");
    //pembuatan object video
    Video video1("A1");
    Video video2("A2");
    Video video3("A3");
    Video video4("A4");
    Video video5("A5");
    Video video6("A6");
    Video video7("A7");
    Video video8("A8");
    Video video9("A9");
    Video video10("A10");

    //pembuatan user
    User user1("Fathir","fathir@gmail.com",20,"fath","B1");
    User user2("Ridwan","Ridwan@gmail.com",19,"wan","B2");
    User user3("Nazwa","Nazwa@gmail.com",18,"naz","B3");
    sistem.addUsersToList(&user1);
    sistem.addUsersToList(&user2);
    sistem.addUsersToList(&user3);

    Channel ch1("Alex",&user1,"02/02/2014","C1");
    sistem.addChannelsToList(&ch1);

    sistem.addVidToListUnuploaded(&video1);
    sistem.addVidToListUnuploaded(&video2);
    sistem.addVidToListUnuploaded(&video3);
    sistem.addVidToListUnuploaded(&video4);
    sistem.addVidToListUnuploaded(&video5);
    sistem.addVidToListUnuploaded(&video6);
    sistem.addVidToListUnuploaded(&video7);
    sistem.addVidToListUnuploaded(&video8);
    sistem.addVidToListUnuploaded(&video9);
    sistem.addVidToListUnuploaded(&video10);

    sistem.addGenresToList(&genre1);
    sistem.addGenresToList(&genre2);
    sistem.addGenresToList(&genre3);


    menu.menuAwal(sistem,play,subs,react);

    return 0;
}
