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
int Balance = 10000;//Баланс
int Bit;//Ставка
int summplayer;//Сумма карт игрока
int summenemy;//Сумма карт соперника
int wins = 0; // победы
int defeats = 0; // поражения
int maxWins = 0; // количество побед
string lastGame; // последняя игра (статус)
string username; // имя игрока

void LoadProfile() {
    system("cls");
    cout << "Enter your nickname: ";
    getline(cin, username);

    username.erase(0, username.find_first_not_of(" \t\n\r\f\v"));
    username.erase(username.find_last_not_of(" \t\n\r\f\v") + 1);

    if (username.empty()) {
        username = "User1";
    }
}

void ChangeUsername() {
    system("cls");
    cout << "Enter new nickname: ";
    getline(cin, username);

    username.erase(0, username.find_first_not_of(" \t\n\r\f\v"));
    username.erase(username.find_last_not_of(" \t\n\r\f\v") + 1);

    if (username.empty()) {
        username = "User1";
    }

    cout << "Nickname successfully changed to: " << username << endl;
    system("pause");
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
                                                 Player's name: )" + username + u8R"(                                                                                                 
                                                 
                                                 Current bet: )" + to_string(Bit) + u8R"(            Balance: )" + to_string(Balance) + u8R"(                                                                                                                                                          
                                                ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝

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
                                                ║                                             [4] Give up                                          ║
                                                ║                                                                                                  ║
                                                ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝

)";
    cout << table;
}

void randomcart(int checkmove)//0-Противник, 1-Игрок
{
    SetConsoleOutputCP(CP_UTF8);
    string carts[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    int numcarts[12] = { 2,3,4,5,6,7,8,9,10,10,10,10 };
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
        cardup[cardplayer + 10] = "|V      |";
        cardmiddle[cardplayer + 10] = "|   S   |";
        carddown[cardplayer + 10] = "|      V|";
    }

    if (value != "10")
    {
        if (checkmove == 0) {
            cardup[cardenemy].replace(cardup[cardenemy].find('V'), 1, value);
            carddown[cardenemy].replace(carddown[cardenemy].find('V'), 1, value);
            cardmiddle[cardenemy].replace(cardmiddle[cardenemy].find('S'), 1, suit);
            cardenemy++;
        }
        else {
            cardup[cardplayer + 10].replace(cardup[cardplayer + 10].find('V'), 1, value);
            carddown[cardplayer + 10].replace(carddown[cardplayer + 10].find('V'), 1, value);
            cardmiddle[cardplayer + 10].replace(cardmiddle[cardplayer + 10].find('S'), 1, suit);
            cardplayer++;
        }
    }
    else {
        if (checkmove == 0) {
            cardup[cardenemy] = "|10     |";
            carddown[cardenemy] = "|     10|";
            cardmiddle[cardenemy].replace(cardmiddle[cardenemy].find('S'), 1, suit);
            cardenemy;
        }
        else {
            cardup[cardplayer + 10] = "|10     |";
            carddown[cardplayer + 10] = "|     10|";
            cardmiddle[cardplayer + 10].replace(cardmiddle[cardplayer + 10].find('S'), 1, suit);
            cardplayer++;
        }
    }
    system("cls");
    drawtable();
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
    ║    - There are double and give up functions.                                                     ║
    ║                                                                                                  ║
    ║  Authors: Vlad and Efim                                                                          ║
    ╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
    )";
    cout << info << endl;
    system("pause");
}

void Profilee() {
    while (true) {
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
  Name: )" + username + u8R"(                                                                         
  Balance: )" + std::to_string(Balance) + u8R"(                                            
  Wins: )" + std::to_string(wins) + u8R"(                                                                        
  Losses: )" + std::to_string(defeats) + u8R"(                                                                   
  Max Win: )" + std::to_string(maxWins) + u8R"(                                                 
  Last Game: )" + lastGame + u8R"(                                                          
╚══════════════════════════════════════════════════════════════════════════════════════════════════╝
)";
        cout << profile << endl;

        cout << "Do you want to change your nickname? (y/n): ";
        char answer;
        cin >> answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка после cin >>

        if (answer == 'y' || answer == 'Y') {
            ChangeUsername();
        } else {
            break;  // Выход из профиля обратно в меню
        }
    }
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
    ║  [3] Default Bet: 50$                                                                            ║
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
    bool bitPlaced = false; // Флаг, ставилась ли ставка
    for (int i = 0; i < 10; i++) {
        cardup[i] = u8"|       |";
        cardup[i + 10] = u8"|       |";
        carddown[i] = u8"|       |";
        carddown[i + 10] = u8"|       |";
        if (i != 9) {
            cardmiddle[i] = u8"|   " + to_string(i + 1) + u8"   |";
            cardmiddle[i + 10] = u8"|   " + to_string(i + 1) + u8"   |";
        }
        else {
            cardmiddle[i] = u8"|   " + to_string(i + 1) + u8"  |";
            cardmiddle[i + 10] = u8"|   " + to_string(i + 1) + u8"  |";
        }
    }
    drawtable();
    Sleep(900);
    for (int i = 0; i < 2; i++) {
        randomcart(1);
        Sleep(800);
    }

    randomcart(0);
    int choice;
    bool takecard = true;//Проверка 
    int temp;//Для добавления ставки
    int action;

    cin >> action;

    if (action == 4) {
        cout << "You've given up. Half of your bet is refunded.\n";
        Balance += Bit / 2;
        Bit = 0;
        Sleep(2000);
        return; // выход из игры
    }
    if (action == 3) {
        if (Balance >= Bit) {
            Balance -= Bit;
            Bit *= 2;
            cout << "The bet is doubled. You get one card.\n";
            randomcart(1);
            Sleep(1000);
            takecard = false; // нельзя больше брать
        }
        else {
            cout << "There are not enough funds to double the bet.\n";
            Sleep(1500);
        }
    }

    while (true) {
        cin >> choice;
        switch (choice) {
        case 1: {
            if (Bit == 0)
            {
                cout << "First you need to place a bit!";
                Sleep(1700);
                system("cls");
                drawtable();
                break;
            }
            if (takecard && cardplayer < 10) {
                randomcart(1);
                break;
            }
        }
        case 2: takecard = false; break;
        default:
            cout << "Invalid choice. Try again.\n";
            Sleep(1500);
            system("cls");
            drawtable();
        }
    }
}

void StartGamePrompt() {
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    int temp;
    char choice;

    cout << "Do you want to play a round of Blackjack? (enter any symbol / n): ";
    cin >> choice;

    if (choice == 'n' || choice == 'N') {
        return; // Возвращает в меню
    }
    while (true) {
        cout << "\nYour balance: " << Balance << endl;
        cout << "Enter your bit (Min: 50$ or 0$ to cancel): ";
        cin >> temp;
        if (temp < 50) return; 
        if (temp == 0) return; // Отмена — назад в меню
        if (temp > 0 && temp <= Balance) {
            Bit = temp;
            Balance -= Bit;
            break; // Успешно — переходим к игре
        } else {
            cout << "Invalid bit! Try again...\n";
            Sleep(2000);
            system("cls");
        }
    }

    NewGamee(); // Запускаем саму игру
}


void Menuu() {
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
        case 1: StartGamePrompt(); break;
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
    LoadProfile();
    Menuu();

    return 0;
}
