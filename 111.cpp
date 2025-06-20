#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <map>
#include <ctime>
#include <cstdlib>
#include <format>

using namespace std;
int check[52][52]; //Список выпавших карт
string cardup[20];//Верхняя часть карты
string cardmiddle[20];//Центральная часть карты
string carddown[20];//Нижняя часть карты
int cardplayer = 0;//Номер взятой карты игрока
int cardenemy = 0;//Номер взятой карты соперника

void randomcart(int checkmove)//0-Противник, 1-Игрок
{
    SetConsoleOutputCP(CP_UTF8);
    string carts[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string suits[4] = { u8"♠", u8"♥", u8"♦", u8"♣" };
    int num = rand() % 13;
    int suitIndex = rand() % 4;

    while (check[num][suitIndex] == 1)
    {
        num = rand() % 13;
        suitIndex = rand() % 4;
    }
    check[num][suitIndex] = 1;
    string value = carts[num];
    string suit = suits[suitIndex];

    if (checkmove == 0) {
        cardup[cardenemy] = "|V      |";
        cardmiddle[cardenemy] = "|   S   |";
        carddown[cardenemy] = "|      V|";
    }
    else {
        cardup[cardplayer+10] = "|V      |";
        cardmiddle[cardplayer + 10] = "|   S   |";
        carddown[cardplayer + 10] = "|      V|";
    }

    if (value != "10")
    {
        if (checkmove == 0) {
            cardup[cardenemy].replace(cardup[cardenemy].find('V'), 1, value);
            carddown[cardenemy].replace(carddown[cardenemy].find('V'), 1, value);
            cardmiddle[cardenemy].replace(cardmiddle[cardenemy].find('S'), 1, suit);
        }
        else {
            cardup[cardplayer + 10].replace(cardup[cardplayer+10].find('V'), 1, value);
            carddown[cardplayer + 10].replace(carddown[cardplayer+10].find('V'), 1, value);
            cardmiddle[cardplayer + 10].replace(cardmiddle[cardplayer + 10].find('S'), 1, suit);
        }
    }
    else {
        if (checkmove == 0) {
            cardup[cardenemy] = "|10     |";
            carddown[cardenemy] = "|     10|";
            cardmiddle[cardenemy].replace(cardmiddle[cardenemy].find('S'), 1, suit);
        }
        else {
            cardup[cardplayer + 10] = "|10     |";
            carddown[cardplayer + 10] = "|     10|";
            cardmiddle[cardplayer+10].replace(cardmiddle[cardplayer+10].find('S'), 1, suit);
        }
    }
}

void drawtable()
{
    string table = u8R"(            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
          %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%                                                                                                             %%%%
       %%%%  _______    _______    _______    _______    _______    _______    _______    _______    _______    _______   %%%%
      %%%%  )" + cardup[0] + "  " + cardup[1] + "  " + cardup[2] + "  " + cardup[3] + "  " + cardup[4] + "  " + cardup[5] + "  " + cardup[6] + "  " + cardup[7] + "  " + cardup[8] + "  " + cardup[9] + u8R"(   %%%%
     %%%%   |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |    %%%%
    %%%%    )" + cardmiddle[0] + "  " + cardmiddle[1] + "  " + cardmiddle[2] + "  " + cardmiddle[3] + "  " + cardmiddle[4] + "  " + cardmiddle[5] + "  " + cardmiddle[6] + "  " + cardmiddle[7] + "  " + cardmiddle[8] + "  " + cardmiddle[9] + u8R"(     %%%%
   %%%%     |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |      %%%%
  %%%%      )" + carddown[0] + "  " + carddown[1] + "  " + carddown[2] + "  " + carddown[3] + "  " + carddown[4] + "  " + carddown[5] + "  " + carddown[6] + "  " + carddown[7] + "  " + carddown[8] + "  " + carddown[9] + u8R"(       %%%%
 %%%%        ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯         %%%%
%%%%                                                                                                                             %%%%
%%%%                                                                                                                             %%%%
%%%%                                                           _______                                                           %%%%
%%%%        dMMMMb     dMP     .aMMMb    .aMMMb     dMP dMP   |\  |  /|            dMMMMMP     .aMMMb    .aMMMb     dMP dMP      %%%%
%%%%       dMP"dMP    dMP     dMP"dMP   dMP"VMP    dMP.dMP    | \ | / |               dMP     dMP"dMP   dMP"VMP    dMP.dMP       %%%%
%%%%======dMMMMK"====dMP=====dMMMMMP===dMP========dMMMMK"==== |--abc--| =============dMP=====dMMMMMP===dMP========dMMMMK"========%%%%
%%%%     dMP.aMF    dMP     dMP dMP   dMP.aMP    dMP"AMF      | / | \ |         dK .dMP     dMP dMP   dMP.aMP    dMP"AMF         %%%%
%%%%    dMMMMP"    dMMMMMP dMP dMP    VMMMP"    dMP dMP       |/  |  \|         VMMMP"     dMP dMP    VMMMP"    dMP dMP          %%%%
%%%%                                                           ¯¯¯¯¯¯¯                                                           %%%%
%%%%                                                                                                                             %%%%
%%%%         _______    _______    _______    _______    _______    _______    _______    _______    _______    _______          %%%%
 %%%%       )" + cardup[10] + "  " + cardup[11] + "  " + cardup[12] + "  " + cardup[13] + "  " + cardup[14] + "  " + cardup[15] + "  " + cardup[16] + "  " + cardup[17] + "  " + cardup[18] + "  " + cardup[19] + u8R"(        %%%%
  %%%%      |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |       %%%%
   %%%%     )" + cardmiddle[10] + "  " + cardmiddle[11] + "  " + cardmiddle[12] + "  " + cardmiddle[13] + "  " + cardmiddle[14] + "  " + cardmiddle[15] + "  " + cardmiddle[16] + "  " + cardmiddle[17] + "  " + cardmiddle[18] + "  " + cardmiddle[19] + u8R"(      %%%%
    %%%%    |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |     %%%%
     %%%%   )" + carddown[10] + "  " + carddown[11] + "  " + carddown[12] + "  " + carddown[13] + "  " + carddown[14] + "  " + carddown[15] + "  " + carddown[16] + "  " + carddown[17] + "  " + carddown[18] + "  " + carddown[19] + u8R"(    %%%%
      %%%%   ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    %%%%
       %%%%                                                                                                               %%%%
         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)";
    cout << table;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        cardup[i] = u8"|       |";
        cardup[i + 10] = u8"|       |";
        carddown[i] = u8"|       |";
        carddown[i + 10] = u8"|       |";
        if (i != 9) {
            cardmiddle[i] = u8"|   " + to_string(i + 1) + u8"   |";
            cardmiddle[i + 10] = u8"|   " + to_string(i + 1) + u8"   |";
        }
        else{
            cardmiddle[i] = u8"|   " + to_string(i + 1) + u8"  |";
            cardmiddle[i + 10] = u8"|   " + to_string(i + 1) + u8"  |";
        }
    }
    for (int i = 0; i <= 10; i++) {
        randomcart(0);
        randomcart(1);
        cardenemy = i;
        cardplayer = i;
    }
    drawtable();

    return 0;
}