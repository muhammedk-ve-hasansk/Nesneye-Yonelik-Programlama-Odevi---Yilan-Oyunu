#ifndef MENU_H //makroyu baslatiyoruz
#define MENU_H  //makroyu tanimliyoruz

// Menu sinifi
class Menu {
    private:
    int choice; // Kullanicinin secimini tutan degisken
    int subChoice; // Alt secimleri tutan degisken

public:
    Menu();   // Menu sinifi contructori
    void showMenu(); // Menuyu ekrana yazdiran fonksiyon prototipi
};

#endif //makroyu bitiriyoruz
