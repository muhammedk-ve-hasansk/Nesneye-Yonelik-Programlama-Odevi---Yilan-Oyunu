#ifndef SNAKEGAME_H //makroyu baslatiyoruz
#define SNAKEGAME_H //makroyu tanimliyoruz

#include <vector> // vector sinifi icin kullanacagimiz kutuphane
#include "GameObject.h" // GameObject sinifini dahil ediyoruz

// Yilan Oyunu Sinifi
class SnakeGame {
private:
    int width, height; // Oyun alaninin genislik ve yuksekligi
    int score; // Oyuncunun skoru
    bool gameOver; // Oyunun bitip bitmedigini kontrol eden degisken
    std::vector<std::pair<int, int>> snakeBody; // Yilanin vucudu
    std::vector<GameObject*> objects; // Oyun nesneleri
    int x, y; // Yilanin basinin x ve y koordinatlari
    char direction; // Yilanin hareket yonu

    void generateGameObjects(); // Oyun nesnelerini olusturan fonksiyon prototipi
    void saveScore(); // Oyunun skorunu dosyaya kaydeden fonksiyon prototipi
    void draw(); // Oyun alanini cizen fonksiyon prototipi
    void input(); // Kullanicinin klavyede bastigi tuslari algilayan fonksiyon prototipi
    void logic(); // Oyunun mantigini kontrol eden fonksiyon prototipi

public:
    SnakeGame(); // Yilan Oyunu Sinifi constructoru
    ~SnakeGame(); // Yilan Oyunu Sinifi destructoru
    void run(); // Oyunun calistigi fonksiyon prototipi
    bool isGameOver(); // Oyunun bitip bitmedigini kontrol eden fonksiyon prototipi
    void displayScores(); // Dosyadan skorlari okuyup ekrana yazdiran fonksiyon prototipi
    void deleteScores(); // Dosyadaki skorlari silen fonksiyon prototipi
};

#endif //makroyu bitiriyoruz
