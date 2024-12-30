 #include "Poison.h" // Poison sinifini dahil ediyoruz
 //zehirin x ve y koordinatlarini alan constructor
    Poison::Poison(int x, int y) : GameObject(x, y) {}
    
    //zehiri terminalde cizdiren fonksiyon
    void Poison::render(){
        std::cout << "&";
    }
     //zehir yenildiginde calisan fonksiyon
    void Poison::interact(int& score, bool& gameOver, std::vector<std::pair<int, int>>& snakeBody, int& width, int& height){
        score -= 5; //skoru azaltiyoruz
        // Yilanin boyunu azalt
        if (snakeBody.size() > 1) {
            snakeBody.pop_back(); // Yilanin son hucresini siliyoruz
        }
    }