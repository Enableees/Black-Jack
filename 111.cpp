#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <map>

using namespace std;

#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void randomcart(int amount)
{
    SetConsoleOutputCP(CP_UTF8); // Для корректного отображения мастей
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    string carts[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    string suits[4] = { u8"♠", u8"♥", u8"♦", u8"♣" };

    for (int i = 0; i < amount; i++)
    {
        int num = rand() % 13; // От 0 до 12
        int suitIndex = rand() % 4;

        string value = carts[num];
        string suit = suits[suitIndex];

        // Базовая форма карты
        string cardTemplate =
            " ______ \n"
            "|V     |\n"
            "|      |\n"
            "|  S   |\n"
            "|      |\n"
            "|     V|\n"
            " ¯¯¯¯¯¯ \n\n";

        // Замена символов V — на номинал, S — на масть
        size_t pos;
        while ((pos = cardTemplate.find('V')) != string::npos)
            cardTemplate.replace(pos, 1, value);

        cardTemplate.replace(cardTemplate.find('S'), 1, suit);

        cout << value + suit << endl;
        cout << cardTemplate;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const string asciiArt = R"(            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
%%%%          Действие бота: f        СТАВКА БОТА: n                             Действие игрока: g      СТАВКА ИГРОКА: m        %%%%
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

    std::cout << asciiArt << std::endl;

    randomcart(5);

    return 0;
}
