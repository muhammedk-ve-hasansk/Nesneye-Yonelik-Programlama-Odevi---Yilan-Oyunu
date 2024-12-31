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
        std::cout << "2. Kurallar\n";
        std::cout << "3. Eski Skorlar\n";
        std::cout << "4. Cikis\n";
        std::cout << "Seciminizi yapin: ";
        std::cin >> choice; // Kullanicinin secimini aliyoruz
        system("cls"); // Konsolu temizliyoruz
        
        // Hatalı girişleri kontrol et
            if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
                std::cin.clear(); // Hata bayrağını temizle
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Geçersiz girdiyi atla
                throw std::invalid_argument("Gecersiz bir secim yaptiniz. Lutfen 1-4 arasinda bir sayi girin.");
            }

        if (choice == 1) { // Eger kullanicinin secimi 1 ise
            game.run(); // Oyunu baslatiyoruz
            
        }
        else if (choice == 2) { // Eger kullanicinin secimi 2 ise
            std::cout << "\n--- Yilan Oyunu Kurallari ---\n";
            std::cout << "1. Yilani yon tuslariyla hareket ettirin.\n";
            std::cout << "2. Meyveleri(O sembolleri) yiyin, puan kazandirir.\n";
            std::cout << "3. Zehirli meyvelerden (& sembolleri) kacinin, puan kaybettirir.\n";
            std::cout << "4. Bombalar (# sembolleri) alani kucultur.\n";
            std::cout << "5. Oyun alanindan cikmak kaybettirir.\n";
            std::cout << "6. Yilaninizin boyutu bir birimden fazlayken eger ters yone gitmeye calisirsaniz yilan kendi kendini isaracagi icin kaybedersiniz.\n";
            std::cout << "Yeniden ana menuye donmek icin bir tusa basin...";
            _getch(); // Kullanicinin bir tusa basmasini bekliyoruz
            system("cls"); // Konsolu temizliyoruz
        } 
        else if (choice == 4) { // Eger kullanicinin secimi 4 ise
            break; // Programi sonlandiriyoruz
        }
        else if(choice == 3){ // Eger kullanicinin secimi 3 ise
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
            system("cls"); // Konsolu temizliyoruz
            if (subChoice == 1) {
                game.deleteScores(); // Skorlari siliyoruz 
            }
            std::cout << "Ana menuye donmek icin bir tusa basin...";
            _getch(); // Kullanicinin bir tusa basmasini bekliyoruz
            system("cls"); // Konsolu temizliyoruz
        } 
        } catch (const std::invalid_argument& e) {
            std::cout << "Hata: " << e.what() << std::endl;
            std::cout << "Ana menuye donmek icin bir tusa basin...";
            _getch();
            system("cls");
        } catch (...) {
            std::cout << "Bilinmeyen bir hata olustu!" << std::endl;
            std::cout << "Ana menuye donmek icin bir tusa basin...";
            _getch();
            system("cls");
        }
    }
}
