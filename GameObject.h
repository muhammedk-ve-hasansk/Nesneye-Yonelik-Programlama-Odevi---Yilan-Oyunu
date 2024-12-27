#ifndef GAMEOBJECT_H  //makroyu baslatiyoruz
#define GAMEOBJECT_H  //makroyu tanimliyoruz

#include <iostream> // cout ve cin kullacagimiz kutuphane
#include <vector> // vector sinifi icin kullanacagimiz kutuphane
#include <utility> // std::pair icin kullanacagimiz kutuphane

// Soyut Sinif: GameObject
class GameObject {
public:
    int x, y; // yilanin x ve y koordinatlari
    GameObject(int x, int y); //yilanin x ve y koordinatlarina deger atayan constructor
    virtual void render() = 0; //terminalde cizim yapmak icin pure virtual fonksiyon
    virtual void interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height) = 0; //oyunun kontrolunu saglayan fonksiyon
    virtual ~GameObject(); //virtual destructor
};

#endif //makroyu bitiriyoruz
