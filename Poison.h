#ifndef POISON_H //makroyu baslatiyoruz
#define POISON_H    //makroyu tanimliyoruz
 
#include "GameObject.h" // GameObject sinifini dahil ediyoruz

// Alt sinif: Zehir (Poison)
class Poison : public GameObject {
public:
    Poison(int x, int y); //zehirin x ve y koordinatlarini alan constructor
    void render() override; //zehiri terminalde cizdiren fonksiyon prototipi
    void interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height) override; //zehir yenildiginde calisan fonksiyon prototipi
}; 

#endif //makroyu bitiriyoruz
