#include "Fruit.h" // Fruit sinifini dahil ediyoruz

Fruit::Fruit(int x, int y) : GameObject(x, y) {} //meyvenin x ve y koordinatlarini alan constructor

//meyveyi terminalde cizdiren fonksiyon
void Fruit::render() { 
    std::cout << "O"; // Meyveyi terminalde O karakteri ile temsil ediyoruz
}
//meyve yenildiginde calisan fonksiyon
void Fruit::interact(int& score, bool&, std::vector<std::pair<int, int>>& snakeBody, int&, int&) {
    score += 10; // Skoru artiriyoruz
    if (!snakeBody.empty()) {
        snakeBody.push_back(snakeBody.back()); // Yilanin basini bir hucre ileri tasiyoruz
    }
}
