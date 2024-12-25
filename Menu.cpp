#include "Menu.h" // Menu sinifini dahil ediyoruz
#include "SnakeGame.h" // Yilan oyunu sinifini dahil ediyoruz
#include <iostream> // cout ve cin kullacagimiz kutuphane
#include <conio.h> // _getch fonksiyonunu icin kullanacagimiz kutuphane
#include <limits> // numeric_limits fonksiyonunu kullanacagimiz kutuphane
// Menu sinifi contructori
Menu::Menu() {
    choice = 0; // Kullanicinin secimini tutan degiskeni sifirliyoruz
    subChoice = 0; // Alt secimleri tutan degiskeni sifirliyoruz
}
// Menuyu ekrana yazdiran fonksiyon
void Menu::showMenu() {
    while (true) {
        SnakeGame game;
        cout << "\n--- Yilan Oyunu ---\n";
        cout << "1. Oyun Baslat\n";
        cout << "2. Kurallar\n";
        cout << "3. Eski Skorlar\n";
        cout << "4. Cikis\n";
        cout << "Seciminizi yapin: ";
        cin >> choice;
        system("cls");

        if (choice == 1) {
            game.run();
        }
        else if (choice == 2) {
            cout << "\n--- Yilan Oyunu Kurallari ---\n";
            cout << "1. Yilani yon tuslariyla hareket ettirin.\n";
            cout << "2. Meyveleri(O sembolleri) yiyin, puan kazandirir.\n";
            cout << "3. Zehirli meyvelerden (& sembolleri) kacinin, puan kaybedetirir.\n";
            cout << "4. Bombalar (# sembolleri) alani kucultur.\n";
            cout << "5. Oyun alanindan cikmak kaybettirir.\n";
            cout << "6. Yilaninizin boyutu bir birimden fazlayken eger ters yone gitmeye calisirsaniz yilan kendi kendini isaracagi icin kaybedersiniz.\n";
            cout << "Yeniden ana menuye donmek icin bir tusa basin...";
            _getch();
            system("cls");
        }
        else if (choice == 4) {
            break;
        }
        else if (choice == 3) {
            game.displayScores();
            cout << "\nEski skorlar silinsin mi?\n";
            cout << "1. Evet\n";
            cout << "2. Hayir\n";
            cout << "Seciminizi yapin: ";
            cin >> subChoice;
            system("cls");
            if (subChoice == 1) {
                game.deleteScores();
            }
            cout << "Ana menuye donmek icin bir tusa basin...";
            _getch();
            system("cls");
        }
        else {
            // Geçersiz bir seçenek girildiğinde kullanıcıya uyarı ver
            cout << "Gecersiz bir secenek girdiniz!\n";
            break;
        }
         
    }
}
