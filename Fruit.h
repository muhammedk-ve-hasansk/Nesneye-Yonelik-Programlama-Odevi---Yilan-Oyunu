#ifndef FRUIT_H //makroyu baslatiyoruz
#define FRUIT_H //makroyu tanimliyoruz

#include "GameObject.h" // GameObject sinifini dahil ediyoruz
// Alt sinif: Meyve (Fruit)
class Fruit : public GameObject {
public:
    Fruit(int x, int y); //meyvenin x ve y koordinatlarini alan constructor
    void render() override; //meyveyi terminalde cizdiren fonksiyon prototipi
    void interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height) override; //meyve yenildiginde calisan fonksiyon prototipi
};

#endif //makroyu bitiriyoruz
