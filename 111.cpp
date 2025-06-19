#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;
int check[52][52];
string randomcart(int amount)
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    string carts[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string suits[4] = { u8"♠", u8"♥", u8"♦", u8"♣" };
    int c;
    int num = 0;
    int suitIndex = 0;
    for (int i = 0; i < amount; i++)
    {
        while (check[num][suitIndex] == 1)
        {
            num = rand() % 13;
            suitIndex = rand() % 4;
        }
        check[num][suitIndex] = 1;
        string value = carts[num];
        string suit = suits[suitIndex];

        string cardTemplate =
            " _______ \n"
            "|V      |\n"
            "|       |\n"
            "|  S    |\n"
            "|       |\n"
            "|      V|\n"
          u8" ¯¯¯¯¯¯¯ ";

        string cardTemplate10 =
            " _______ \n"
            "|10     |\n"
            "|       |\n"
            "|  S    |\n"
            "|       |\n"
            "|     10|\n"
          u8" ¯¯¯¯¯¯¯ ";

        size_t pos;
        if (value != "10")
        {
            while ((pos = cardTemplate.find("V")) != string::npos)
                cardTemplate.replace(pos, 1, value);

            cardTemplate.replace(cardTemplate.find('S'), 1, suit);
            return cardTemplate;
        }
        else {
            cardTemplate10.replace(cardTemplate.find('S'), 1, suit);
            return cardTemplate10;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, "Russian");
    string table = u8R"(            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
          %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %%%%                                                                                                             %%%%
       %%%%  _______    _______    _______    _______    _______    _______    _______    _______    _______    _______   %%%%
      %%%%  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |   %%%%
     %%%%   |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |    %%%%
    %%%%    |   1   |  |   2   |  |   3   |  |   4   |  |   5   |  |   6   |  |   7   |  |   8   |  |   9   |  |   10  |     %%%%
   %%%%     |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |      %%%%
  %%%%      |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |       %%%%
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
 %%%%       |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |        %%%%
  %%%%      |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |       %%%%
   %%%%     |   1   |  |   2   |  |   3   |  |   4   |  |   5   |  |   6   |  |   7   |  |   8   |  |   9   |  |   10  |      %%%%
    %%%%    |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |     %%%%
     %%%%   |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |    %%%%
      %%%%   ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    ¯¯¯¯¯¯¯    %%%%
       %%%%                                                                                                               %%%%
         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%)";

    table.insert(770, randomcart(1));
    cout << table << endl;

    //randomcart(52);

    return 0;
}