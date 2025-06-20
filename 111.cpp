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
                                string table = u8R"(                                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
                                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


                                                ╔══════════════════════════════════════════════════════════════════════════════════════════════════╗
                                                ║        /$$$$$$   /$$$$$$  /$$      /$$ /$$      /$$  /$$$$$$  /$$   /$$ /$$$$$$$   /$$$$$$       ║
                                                ║       /$$__  $$ /$$__  $$| $$$    /$$$| $$$    /$$$ /$$__  $$| $$$ | $$| $$__  $$ /$$__  $$      ║
                                                ║      | $$  \__/| $$  \ $$| $$$$  /$$$$| $$$$  /$$$$| $$  \ $$| $$$$| $$| $$  \ $$| $$  \__/      ║
                                                ║      | $$      | $$  | $$| $$ $$/$$ $$| $$ $$/$$ $$| $$$$$$$$| $$ $$ $$| $$  | $$|  $$$$$$       ║
                                                ║      | $$      | $$  | $$| $$  $$$| $$| $$  $$$| $$| $$__  $$| $$  $$$$| $$  | $$ \____  $$      ║
                                                ║      | $$    $$| $$  | $$| $$\  $ | $$| $$\  $ | $$| $$  | $$| $$\  $$$| $$  | $$ /$$  \ $$      ║
                                                ║      |  $$$$$$/|  $$$$$$/| $$ \/  | $$| $$ \/  | $$| $$  | $$| $$ \  $$| $$$$$$$/|  $$$$$$/      ║
                                                ║       \______/  \______/ |__/     |__/|__/     |__/|__/  |__/|__/  \__/|_______/  \______/       ║
                                                ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
                                                ║  Authors:                                   VLad and Efim                                        ║
                                                ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
                                                ║                                                                                                  ║
                                                ║                                             [1] More                                             ║
                                                ║                                             [2] Stop                                             ║
                                                ║                                             [3] Double                                           ║
                                                ║                                             [4] Split                                            ║
                                                ║                                             [5] Give up                                          ║
                                                ║                                                                                                  ║
                                                ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝

)";
    cout << table;
}

void infoo() {
    system("cls");
    string info = u8R"(
    ╔══════════════════════════════════════════════════════════════════════════════════════════════════╗
    ║                                                                                                  ║
    ║                                 /$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$                              ║
    ║                                |_  $$_/| $$$ | $$| $$_____//$$__  $$                             ║
    ║                                  | $$  | $$$$| $$| $$     | $$  \ $$                             ║
    ║                                  | $$  | $$ $$ $$| $$$$$  | $$  | $$                             ║
    ║                                  | $$  | $$  $$$$| $$__/  | $$  | $$                             ║
    ║                                  | $$  | $$\  $$$| $$     | $$  | $$                             ║
    ║                                 /$$$$$$| $$ \  $$| $$     |  $$$$$$/                             ║
    ║                                |______/|__/  \__/|__/      \______/                              ║
    ║                                                                                                  ║
    ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
    ║  Game: ASCII Blackjack (21)                                                                      ║
    ║  Version: 1.0                                                                                    ║
    ║                                                                                                  ║
    ║  Description:                                                                                    ║
    ║    This is a console card game in the classic Blackjack style.                                   ║
    ║    Goal: Get 21 points or closer than the dealer, without busting.                               ║
    ║                                                                                                  ║
    ║  Card Values:                                                                                    ║
    ║    - Ace: 1 or 11                                                                                ║
    ║    - Cards 2-10: Face value                                                                      ║
    ║    - Jack, Queen, King: 10                                                                       ║
    ║                                                                                                  ║
    ║  Flow:                                                                                           ║
    ║    - Player acts first: "More" or "Stop"                                                         ║
    ║    - Dealer draws until 17 or more                                                               ║
    ║    - There are split, double and give up functions.                                              ║
    ║                                                                                                  ║
    ║  Authors: Vlad and Efim                                                                          ║
    ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
    cout << info << endl;
    system("pause");
}

void Profilee() {
    system("cls");
    string profile = u8R"(
    ╔══════════════════════════════════════════════════════════════════════════════════════════════════╗
    ║                                                                                                  ║
    ║                /$$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$ /$$       /$$$$$$$$               ║
    ║               | $$__  $$| $$__  $$ /$$__  $$| $$_____/|_  $$_/| $$      | $$_____/               ║
    ║               | $$  \ $$| $$  \ $$| $$  \ $$| $$        | $$  | $$      | $$                     ║
    ║               | $$$$$$$/| $$$$$$$/| $$  | $$| $$$$$     | $$  | $$      | $$$$$                  ║
    ║               | $$____/ | $$__  $$| $$  | $$| $$__/     | $$  | $$      | $$__/                  ║
    ║               | $$      | $$  \ $$| $$  | $$| $$        | $$  | $$      | $$                     ║
    ║               | $$      | $$  | $$|  $$$$$$/| $$       /$$$$$$| $$$$$$$$| $$$$$$$$               ║
    ║               |__/      |__/  |__/ \______/ |__/      |______/|________/|________/               ║
    ║                                                                                                  ║
    ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
    ║  Name: имя пользователя, вводится им же                                                          ║
    ║  Balance: изменяемый баланс (10 000 с самого начала)                                             ║
    ║  Wins: победы (считаются)                                                                        ║
    ║  Losses: поражения (считаются)                                                                   ║
    ║  Max Win: максимальные деньги, которые имел юзер                                                 ║
    ║  Last Game: статус игры (последней)                                                              ║
    ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
    cout << profile << endl;
    system("pause");
}

void Settingss() {
    system("cls");
    string settings = u8R"(
    ╔══════════════════════════════════════════════════════════════════════════════════════════════════╗
    ║                                                                                                  ║
    ║           /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$ /$$   /$$  /$$$$$$   /$$$$$$            ║
    ║          /$$__  $$| $$_____/|__  $$__/|__  $$__/|_  $$_/| $$$ | $$ /$$__  $$ /$$__  $$           ║
    ║         | $$  \__/| $$         | $$      | $$     | $$  | $$$$| $$| $$  \__/| $$  \__/           ║
    ║         |  $$$$$$ | $$$$$      | $$      | $$     | $$  | $$ $$ $$| $$ /$$$$|  $$$$$$            ║
    ║          \____  $$| $$__/      | $$      | $$     | $$  | $$  $$$$| $$|_  $$ \____  $$           ║
    ║          /$$  \ $$| $$         | $$      | $$     | $$  | $$\  $$$| $$  \ $$ /$$  \ $$           ║
    ║         |  $$$$$$/| $$$$$$$$   | $$      | $$    /$$$$$$| $$ \  $$|  $$$$$$/|  $$$$$$/           ║
    ║          \______/ |________/   |__/      |__/   |______/|__/  \__/ \______/  \______/            ║
    ║                                                                                                  ║
    ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
    ║  [1] Dealer Difficulty: Standard                                                                 ║
    ║  [2] Language: English                                                                           ║
    ║  [3] Default Bet: $50                                                                            ║
    ║  [4] Theme: Classic (White on Black)                                                             ║
    ║                                                                                                  ║
    ║  * Settings are static in this version. Editable in future builds.                               ║
    ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
    cout << settings << endl;
    system("pause");
}

void Exitt() {
    system("cls");
    cout << "Exiting game..." << endl;
    exit(0);
}

void NewGamee() {
    system("cls");
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
    // system("cls");
    
    /*while (true) {
        if (GetKeyState(VK_LBUTTON)) {
            cout << "2224\n";
        }
    }*/
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    COORD coord; // для координат X, Y

    SetConsoleMode(hin, ENABLE_MOUSE_INPUT);
    //while (true)
    //{
    //    ReadConsoleInput(hin, &InputRecord, 1, &Events); // считывание 

    //    if (InputRecord.Event.MouseEvent.dwButtonState == MOUSE_WHEELED) // нажато колесико
    //    {
    //        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    //        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
    //        cout << "Kolesiko nazhato - X" << coord.X << ", Y = " << coord.Y << endl;
    //    }
    //    else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // правая кнопка
    //    {
    //        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    //        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
    //        cout << "right - X" << coord.X << ", Y = " << coord.Y << endl;
    //    }
    //    else if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // левая кнопка
    //    {
    //        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    //        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
    //        cout << "left - X" << coord.X << ", Y = " << coord.Y << endl;
    //    }

    //}
    system("pause");               //          ПО ХОРОШЕМУ МОЖНО УДАЛИТЬ, ДЛЯ УДОБСТВА!!!
}

void Menuu(){
    while (true) {
        system("cls");
        string menuuu = u8R"( 
        ╔══════════════════════════════════════════════════════════════════════════════════════════════════╗
        ║  /$$$$$$$  /$$        /$$$$$$   /$$$$$$  /$$   /$$          /$$$$$  /$$$$$$   /$$$$$$  /$$   /$$ ║
        ║ | $$__  $$| $$       /$$__  $$ /$$__  $$| $$  /$$/         |__  $$ /$$__  $$ /$$__  $$| $$  /$$/ ║
        ║ | $$  \ $$| $$      | $$  \ $$| $$  \__/| $$ /$$/             | $$| $$  \ $$| $$  \__/| $$ /$$/  ║
        ║ | $$$$$$$ | $$      | $$$$$$$$| $$      | $$$$$/              | $$| $$$$$$$$| $$      | $$$$$/   ║
        ║ | $$__  $$| $$      | $$__  $$| $$      | $$  $$         /$$  | $$| $$__  $$| $$      | $$  $$   ║
        ║ | $$  \ $$| $$      | $$  | $$| $$    $$| $$\  $$       | $$  | $$| $$  | $$| $$    $$| $$\  $$  ║
        ║ | $$$$$$$/| $$$$$$$$| $$  | $$|  $$$$$$/| $$ \  $$      |  $$$$$$/| $$  | $$|  $$$$$$/| $$ \  $$ ║
        ║ |_______/ |________/|__/  |__/ \______/ |__/  \__/       \______/ |__/  |__/ \______/ |__/  \__/ ║
        ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
        ║  Authors:                                   VLad and Efim                                        ║
        ╠══════════════════════════════════════════════════════════════════════════════════════════════════╣
        ║                                                                                                  ║
        ║                                             [1] New Game                                         ║
        ║                                             [2] info                                             ║
        ║                                             [3] Profile                                          ║
        ║                                             [4] Settings                                         ║
        ║                                             [5] Exit                                             ║
        ║                                                                                                  ║
        ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
        
        )";
        cout << menuuu;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: NewGamee(); break;
            case 2: infoo(); break;
            case 3: Profilee(); break;
            case 4: Settingss(); break;
            case 5: Exitt(); break;
            default:
                cout << "Invalid choice. Try again.\n";
                Sleep(1500);
                break;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
    Menuu();

    return 0;
}
