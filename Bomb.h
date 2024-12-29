#ifndef BOMB_H //makroyu baslatiyoruz
#define BOMB_H //makroyu tanimliyoruz

#include "GameObject.h" // GameObject sinifini dahil ediyoruz
// Alt sinif: Bomba (Bomb)
class Bomb : public GameObject {
public:
    Bomb(int x, int y); //bombanin x ve y koordinatlarini alan constructor
    void render() override; //bombalari terminalde cizdiren fonksiyon prototipi
    void interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height) override; //bomba yenildiginde calisan fonksiyon prototipi
};

#endif //makroyu bitiriyoruz
