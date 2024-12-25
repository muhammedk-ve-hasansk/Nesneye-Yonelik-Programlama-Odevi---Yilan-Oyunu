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
        SnakeGame game; // Yilan oyunu sinifindan bir nesne turetiyoruz
        try{
        std::cout << "\n--- Yilan Oyunu ---\n";
        std::cout << "1. Oyun Baslat\n";
        std::cout << "2. Eski Skorlar\n";
        std::cin >> choice; // Kullanicinin secimini aliyoruz
        
        // Hatalı girişleri kontrol et
            if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
                std::cin.clear(); // Hata bayrağını temizle
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Geçersiz girdiyi atla
                throw std::invalid_argument("Gecersiz bir secim yaptiniz. Lutfen 1-4 arasinda bir sayi girin.");
            }

        if (choice == 1) { // Eger kullanicinin secimi 1 ise
            game.run(); // Oyunu baslatiyoruz
            
        }
        else if(choice == 2){ // Eger kullanicinin secimi 3 ise
         game.displayScores(); // Skorlari ekrana yazdiriyoruz
            std::cout << "\nEski skorlar silinsin mi?\n";
            std::cout << "1. Evet\n";
            std::cout << "2. Hayir\n";
            std::cout << "Seciminizi yapin: ";
            std::cin >> subChoice; // Kullanicinin secimini aliyoruz

            // Hatalı girişleri kontrol et
                if (std::cin.fail() || (subChoice != 1 && subChoice != 2)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Gecersiz bir secim yaptiniz. Lutfen 1 veya 2 girin.");
                }
            if (subChoice == 1) {
                game.deleteScores(); // Skorlari siliyoruz 
            }
            std::cout << "Ana menuye donmek icin bir tusa basin...";
            _getch(); // Kullanicinin bir tusa basmasini bekliyoruz
        } 
        } catch (const std::invalid_argument& e) {
            std::cout << "Hata: " << e.what() << std::endl;
            std::cout << "Ana menuye donmek icin bir tusa basin...";
            _getch() ;  
        } 
    }
}
