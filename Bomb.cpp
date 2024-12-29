#include "Bomb.h" // Bomb sinifini dahil ediyoruz
//bombanin x ve y koordinatlarini alan constructor
    Bomb::Bomb(int x, int y) : GameObject(x, y) {}
    //bombalari terminalde cizdiren fonksiyon
    void Bomb::render(){
        std::cout << "#"; // Bombayi terminalde # karakteri ile temsil ediyoruz
    }
    //bomba yenildiginde calisan fonksiyon
    void Bomb::interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height){
        // Oyun alanini daraltiyoruz
        if (width > 20 && height > 10) {
            width -= 5;
            height -= 2;
        }
    }